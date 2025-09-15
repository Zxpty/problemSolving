#include <algorithm>
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
  vector<int> a(n),b(n);
  for(int& x : a) cin>>x;
  for(int& x : b) cin>>x;
  int mx1 = *max_element(a.begin(),a.end());
  int mx2 = *max_element(b.begin(),b.end());
  ll ans = 1LL*(mx1+mx2);
  cout<<ans;
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


