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
  vector<int> dp(3);
  for(int day=0;day<n;day++){
    vector<int> new_dp(3,0);
    vector<int> c(3);
    for(int i=0;i<3;i++){
      cin>>c[i];
    }
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(i!=j){
          new_dp[j] = max(new_dp[j],dp[i]+c[j]);
          dbg(dp[i]+c[j]);
          dbg(j,new_dp[j]);
        }
      }
    }
    dbg(new_dp);
    dp = new_dp;
  }
  cout<<max({dp[0],dp[1],dp[2]});
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

