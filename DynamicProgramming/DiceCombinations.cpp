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
const int MX= 1e6+7;
vector<ll> dp(MX,0);
void init(){
  dp[0]=1;
  dp[1]=1;
  for(int i=2;i<MX;i++){
    for(int j=1;j<=6;j++){
      dp[i]+=((i-j>=0 ? dp[i-j]:0));
      dp[i]%=mod;
    }
  }
}
void solve()
{
  int n; cin>>n;
  cout<<dp[n]<<'\n';
}
int main()
{
    cpu();
    int t = 1;
    init();
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

