#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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
  int n,d; cin>>n>>d;
  vector<int> r(n);
  for(int& x : r) cin>>x;
  d%=n;
  reverse(r.begin(),r.begin()+d);
  dbg(r);
  reverse(r.begin()+d,r.end());
  dbg(r);
  reverse(r.begin(),r.end());
  dbg(r);
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


