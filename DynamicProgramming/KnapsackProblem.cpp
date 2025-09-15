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
  int n,x; cin>> n >> x;
  vector<pair<int,int>> r(n); // elemento y peso
  for(int i = 0; i < n; i++){
    int val,weight; cin>>val>>weight;
    r[i] = {val,weight};
  }
  
  vector<vector<int>> dp(n+1,vector<int>(n+1));
  for(int i=n;i>=0;i--){
    for(int j=0;j<=x;j++){
      dp[i][j] = dp[i-1][j];
      if(j-r[i-1].second>=0){
        dp[i][j]= min(dp[i][j],r[i].second+dp[i-1][j]);
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

