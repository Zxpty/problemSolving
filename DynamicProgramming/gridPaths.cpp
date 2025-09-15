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
  int n; cin>>n;
  vector<vector<char>> grid(n,vector<char>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>grid[i][j];
    }
  }

  vector<vector<int>> dp(n,vector<int>(n));
  dp[0][0] = 1;
  if(grid[0][0]=='*'|| grid[n-1][n-1]=='*'){
    cout<<"0\n";
    return;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       if(j-1>=0){
         if(grid[i][j-1]!='*'){
          dp[i][j]+=dp[i][j-1];
          dp[i][j]%=mod;
         }
      }
      if(i-1>=0){
        if(grid[i-1][j]!='*'){
         dp[i][j]+=dp[i-1][j];
         dp[i][j]%=mod;
        }
    }
      dbg(dp[i][j]);
    }
    dbg(dp[3][0]);
    
  }
  cout<<dp[n-1][n-1]<<'\n';
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

