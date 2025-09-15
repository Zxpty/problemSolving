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
void max_self(int& a, int b){
  a = max(a,b);
}
void solve()
{
  int n,w; cin>>n>>w;
  vector<int> dp(w+1);
  for(int item = 0; item < n ; item++){
    int weight,value; cin>>weight>>value;
    for(int weight_already= w-weight;weight_already>=0;weight_already--){
      max_self(dp[weight_already+weight], dp[weight_already]+value);
    }
  }
  int ans = 0;
  for(int i=0;i<=w;i++){
    max_self(ans, dp[i]);
  }
  cout<<ans<<'\n';
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

