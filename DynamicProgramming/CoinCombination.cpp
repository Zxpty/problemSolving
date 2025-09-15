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
  int n,target; cin>>n>>target;
  vector<ll> c(n);
  for(ll& x : c) cin>>x;
  vector<int> dp(target+1,0);
  dp[0]=1;

  for(int x : c){
  for(int i=1;i<=target;i++){
      dp[i]+=(i-x>=0 ? dp[i-x]:0);
      dp[i]%=mod;
    }
  }
  cout<<dp[target]<<'\n';
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

