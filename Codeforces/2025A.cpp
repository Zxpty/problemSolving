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
  string s,x; cin>>s>>x;
  int n = s.size();
  int m = x.size();

  int l = 0;
  while(l<n && l<m && s[l]==x[l])l++;
  int ans = (n-l)+(m-l)+l+1;
  cout<<min(n+m,ans)<<'\n';
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

