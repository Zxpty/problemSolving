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
  string s; cin>>s;
  vector<ll> f(2);
  for(auto x : s){
    f[x-'0']++;
  }
  ll fo = 1LL*(f[0]*f[1]);
  //dbg(fo);
  ll ans = fo;
  int l = 0;
  while(l<n){
    int r = l;
    int cn =1;
    while(r+1<n && s[l]==s[r+1]){
      cn++;
      r++;
    }
    l = r+1;
    //dbg(s[l]);
    //dbg(cn*cn);
    ans = max(ans,1LL*cn*cn);
  }
  cout<<ans<<'\n';
}
int main()
{
    cpu();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


