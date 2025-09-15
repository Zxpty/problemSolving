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
void solve()
{
  ll n; cin>>n;
  vector<int> r(n);
  for(int& x : r) cin>>x;
  map<int,vector<int>> pos;
  //dbg(r);
  for(int i=0;i<n;i++){
    pos[r[i]].push_back(i);
  }
  vector<pair<int,int>> ans;
  for(auto x : pos){
    int val = x.first;
    vector<int> pos = x.second;
    if(pos.size()==1){
      ans.emplace_back(val,0);
    }else{
      bool ok = true;
      int diff =  pos[1]-pos[0];
      for(int i=2;i<(int)pos.size();i++){
        if(pos[i]-pos[i-1]!=diff){
          ok = false;
          break;
        }
      }
      if(ok){
        ans.emplace_back(val,diff);
      }
    }
   
  }
    cout<<(int)ans.size()<<'\n';
    for(auto x : ans){
      cout<<x.first<<" "<<x.second<<'\n';
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

