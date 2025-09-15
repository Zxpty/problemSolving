#include <bits/stdc++.h>
#include <climits>
#include <string>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int MNUM = 1e6+1;
const int INF = 1e9;
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
      if(a.first>b.first){
        return a;
      }else return b;
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
        T ans = {-INF,0};
        while(first <= last){
            if(first % 2 == 1) ans = compare(ans, tree[first++]);
            if(last % 2 == 0) ans = compare(ans, tree[last--]);
            first >>= 1, last >>= 1;
        }
        return ans;
    }
};


segment_tree<pair<int,int>> test(MNUM);
void init(){
  for(int i=1;i<MNUM;i++){
    string y = to_string(i);
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(int j=0;j<y.size();j++){
      mn = min(mn,y[j]-'0');
      mx = max(mx,y[j]-'0');
    }
    test.modify(i,{abs(mx-mn),i});
  }
}

void solve()
{
  int a,b; cin>>a>>b;
  auto [mx,num] = test.query(a, b);
  cout<<num<<'\n';

}
int main()
{
    cpu();
    init();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

