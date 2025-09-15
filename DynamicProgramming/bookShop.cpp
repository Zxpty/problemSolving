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
  int n,x; cin>>n>>x;
  vector<int> h(n),s(n);
  for(int& x : h) cin>>x;
  for(int& x : s) cin>>x;
  dbg(h);
  dbg(s);
  vector<vector<int>> dp(n+1,vector<int>(x+1));
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= x; j++){
      dp[i][j] = dp[i-1][j];
      if(j-h[i-1]>=0){
        dp[i][j] = max(dp[i][j],s[i-1]+dp[i-1][j-h[i-1]]);
      }
    }
  }
  dbg(dp);
  cout<<dp[n][x]<<'\n';


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

