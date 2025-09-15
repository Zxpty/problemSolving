#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
  ll n,x; cin>>n>>x;
  vector<ll> p(n);
  for(ll& x : p) cin>>x;
  ll mx = *max_element(p.begin(),p.end());
  ll sum = 0;
  for(int i=0;i<n;i++){
    sum+=p[i];
  }
  ll op = (sum+x-1)/x;
  dbg(op);
  ll ans = max(mx,(sum+x-1)/x);
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

