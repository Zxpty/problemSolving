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
const int MX =1e6+7;
vector<int> dp(MX,MX);

void init(){
  auto check =[&](int x){
    string s = to_string(x);
    int mx = -1;
    for(int i=0;i<(int)s.size();i++){
      mx = max(mx,s[i]-'0');
    }
    return mx;
  };
  dp[0] = 0;
  for(int i=1;i<=MX;i++){
    int c = check(i);
    dp[i] = min(dp[i],dp[i-c]+1);
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

