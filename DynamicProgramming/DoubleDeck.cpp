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
  vector<int> a(n*k),b(n*k);
  for(int& x : a) cin>>x;
  for(int& x : b) cin>>x;
  dbg(a);
  dbg(b);

  vector<vector<int>> dp(2,vector<int>(n*k));
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

