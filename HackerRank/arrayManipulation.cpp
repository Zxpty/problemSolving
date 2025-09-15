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
  ll n,m; cin>>n>>m;
  vector<ll> ar(n,0);
  while(m--){
    ll a,b,k; cin>>a>>b>>k;
    a--,b--;
    ar[a]+=k;
    dbg(a,ar[a]);
    dbg(ar);
    if(b+1<n)ar[b+1]-=k;
    dbg(ar);
  }
 ll current = 0, mx = 0;
    for (ll i = 0; i < n; i++) {
        current += ar[i];
        mx = max(mx, current);
    }
    cout << mx << "\n"; 
  
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


