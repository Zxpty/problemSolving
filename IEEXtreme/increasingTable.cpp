#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const int MOD = 998244353;
void solve()
{
  int n; cin>>n;
  int x,y; cin>>x;
  vector<int> a(x);
  for(int& p : a) cin>>p;
  cin>>y;
  vector<int> b(y);
  for(int& p : b) cin>>p;
  vector<bool> enA(2*n+1,false),enB(2*n+1,false);
  for(int num : a)enA[num] = true;
  for(int num : b)enB[num] = true;
  vector<ll> dp(n+1,0);
  dp[0]=1;
  for(int num=1;num<=2*n;num++){
    vector<ll> new_dp(n+1,0);
    for(int i=1;i<=n;i++){
      if(dp[i]==0) continue;
       if(i<n && (enA[num])||(!enA[num])&&!enB[num]){
        if(i==0||num>(2*(i-1)+1)){
          new_dp[i+1] = (new_dp[i+1]+dp[i])%MOD;
        }
      }
        if(i<n && (enB[num])||(!enA[num])&&!enB[num]){
        if(i==0||num>(2*(i-1)+2)){
          new_dp[i+1] = (new_dp[i+1]+dp[i])%MOD;
        }
      }

     
    }
    dp = new_dp;
  }
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

