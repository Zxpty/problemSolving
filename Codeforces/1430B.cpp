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
  int n,k; cin>>n>>k;
  vector<ll> r(n);
  for(ll& x : r) cin>>x;
  sort(r.rbegin(),r.rend());
  ll sum = 0;
  dbg(r);
  for(int i=0;i<=k;i++){
    sum+=r[i];
  }
  cout<<sum<<'\n';
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


