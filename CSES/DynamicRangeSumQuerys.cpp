#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
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
        return a + b;
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
        T ans = 0;
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
  segment_tree<ll> st(n);
  for(int i=0;i<n;i++){
    ll num; cin>>num;
    st.modify(i, num);
  }
  while(q--){
    int op; cin>>op;
    int k,l,r;
    ll u;
    if(op==1){
      cin>>k;
      cin>>u;
      st.modify(k-1, u);
    }else if(op==2){
      cin>>l>>r;
      l--,r--;
      cout<<st.query(l, r)<<'\n';
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

