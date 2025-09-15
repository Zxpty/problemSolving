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
const int INF = 1e9+5;
void solve()
{
  int n; cin>>n;
  int k; cin>>k;
  vector<int> r(n);
  for(int& x : r) cin>>x;
  vector<int> dp(n,INF);
  dp[0] = 0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<=i+k;j++){
      if(j<n){
        dp[j]=min(dp[j],dp[i]+abs(r[i]-r[j]));
      }
    }
  }
  cout<<dp[n-1]<<'\n';
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


