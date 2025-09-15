#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

struct node{
  int fmx;
  int smx;
  int cnf;
  int cns;
  node(){
    this->fmx = 0;
    this->smx = 0;
    this->cnf = 0;
    this->cns = 0;
  }
  node(int fmx, int smx, int cnf,int cns){
    this->fmx = fmx;
    this->smx = smx;
    this->cnf = cnf;
    this->cns = cns;
  }
};

template<class T>
struct segment_tree{
    int n; 
    vector<T> tree;

    segment_tree(int n){
        this -> n = n;
        tree.resize(2 * n);
    }

    segment_tree(vector<T>& values){
        this -> n = values.size();
        tree.resize(2 * n);
        for(int i = 0; i < n; i++) upd(i, values[i]);
    }
    
    //CHANGE
    T compare(T a, T b){
      T ans;
      if(a.fmx==b.fmx){
        ans.fmx = a.fmx;
        ans.cnf = a.cnf+b.cnf;
        if(a.smx>b.smx){
          ans.smx = a.smx;
          ans.cns = a.cns;
        } 
        if(a.smx==b.smx){
          ans.smx = a.smx;
          ans.cns = a.cns+b.cns;
        }
        if(a.smx<b.smx){
          ans.smx = b.smx;
          ans.cns = b.cns;
        }
      }else if(a.fmx>b.fmx){
         ans.fmx = a.fmx;
         ans.cnf = a.cnf;
        if(a.smx>b.fmx){
          ans.smx = a.smx;
          ans.cns = a.cns;
        }
        if(a.smx==b.fmx){
          ans.smx = a.smx;
          ans.cns = a.cns+b.cnf;
        }
        if(b.fmx>a.smx){
          ans.smx = b.fmx;
          ans.cns = b.cnf;
        }
     }else{
        ans.fmx = b.fmx;
        ans.cnf = b.cnf;
        if(b.smx>a.fmx){
          ans.smx = b.smx;
          ans.cns = b.cns;
        }
        if(b.smx==a.fmx){
          ans.smx = b.smx;
          ans.cns = b.cns + a.cnf;
        }
        if(b.smx<a.fmx){
          ans.smx = a.fmx;
          ans.cns = a.cnf;
        }
      }
      return ans;
    }

    void modify(int index, T value){
        index += n;
        tree[index] = value;
        for(index >>= 1; index >= 1; index >>= 1) tree[index]= compare(tree[2 * index], tree[2 * index + 1]);
    }

    void upd(int index, T value){
        index += n;
        tree[index] = compare(tree[index], value);
        for(index >>= 1; index >= 1; index >>= 1) tree[index]= compare(tree[2 * index], tree[2 * index + 1]);
    }
    
    //BOTTOM - TOP
    T query(int first, int last){
        first += n, last += n;
        T ans;
        while(first <= last){
            if(first % 2 == 1) ans = compare(ans, tree[first++]);
            if(last % 2 == 0) ans = compare(ans, tree[last--]);
            first >>= 1, last >>= 1;
        }
        return ans;
    }
};



void solve()
{
  int n,q; cin>>n>>q;
  segment_tree<node> test(n);
  for(int i=0;i<n;i++){
    int num; cin>>num;
    test.modify(i, node(num,0,1,0));
  }
  while(q--){
    int op,p,x,l,r;
    cin>>op;
    if(op==1){
      cin>>p>>x;
      test.modify(p-1, node(x,0,1,0));
    }else if(op==2){
      cin>>l>>r;
      l--,r--;
      cout<<test.query(l, r).cns<<'\n';
    }
  }

}
int main()
{
    cpu();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

