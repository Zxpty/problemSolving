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
const int MX = 1e6+7;
void solve()
{
  // f(x) = minimo numero de coins que sumen x
  int n,target; cin>>n>>target;
  vector<int> C(n);
  for(int& x : C) cin>>x;
  vector<int> dp(target+1,MX);
  dp[0] = 0;
  for(int i=1;i<=target;i++){
    for(int c : C){
      dp[i] = min(dp[i],(i-c>=0?dp[i-c]+1:MX));
    }
  }
  if(dp[target]!=MX){
    cout<<dp[target]<<'\n';
    return;

  }
  cout<<"-1\n";
  return;

}
int main()
{
    //cpu();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

