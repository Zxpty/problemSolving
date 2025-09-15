#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;
void solve()
{
  int n,k; cin>>n>>k;
  vi r(n);
  for(int& x : r) cin>>x;
  bool ok = 0;
  for(int i = 0; i<n; i++) if(r[i]==k){ok = 1; break;}
  cout<<(ok ? "YES" : "NO")<<'\n';
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

