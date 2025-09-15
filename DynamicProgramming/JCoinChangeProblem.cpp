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
  int n,m; cin>>n>>m;
  vector<int> r(m);
  for(int& x : r) cin>>x;
  vector<int> dp(n+1,mod);
  dp[0] = 0;
  for(int i=1;i<=n;i++){
    for(int x : r){
      if(i-x>=0){
        dp[i]= min(dp[i],dp[i-x]+1);
      }
    }
  }
  dbg(dp);
  cout<<dp[n]<<'\n';
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

