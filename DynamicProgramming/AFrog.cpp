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
const int MX = 1e9+7;
void solve()
{
  // f(x) = minimo costo antes que el sapo llegue a x, i+1,i+2
  // f[x] += min(f[x]+abs(r[i]-r[i+1]),f[x]+abs(r[i]-r[i+2]))
  int n; cin>>n;
  vector<int> r(n);
  for(int& x : r)cin>>x;
  vector<int> dp(n,MX);
  dp[0]=0;
  for(int i=0;i<n;i++){
    if(i+1<n){
      dp[i+1] = min(dp[i+1],dp[i]+abs(r[i]-r[i+1]));
    }
    if(i+2<n){
      dp[i+2] = min(dp[i+2],dp[i]+abs(r[i]-r[i+2]));
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

