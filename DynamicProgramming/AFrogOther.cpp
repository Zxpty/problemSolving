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
const int INF = 1e9+7;
void solve()
{
  // f(x) = minimo costo para llegar a x
  // f[x] = min(f[x-1]+abs(r[i]-r[i-1]),f[x-2]+abs(r[i]-r[x-2]));
  // f[x] = min(f[x],f[x-j])
  int n,k; cin>>n>>k;
  vector<int> r(n);
  for(int& x :r )cin>>x;
  vector<int> dp(n,INF);
  dp[0]=0;
  dp[1] = abs(r[1]-r[0]);
  for(int i=2;i<n;i++){
    for(int j=1;j<=k;j++){
      if(i-j>=0){
        dp[i]= min(dp[i],dp[i-j]+abs(r[i]-r[i-j]));
        dbg(dp[i-j]);
        dbg(i,dp[i]);
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

