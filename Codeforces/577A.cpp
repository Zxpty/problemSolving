#include <bits/stdc++.h>
#include <ratio>
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
  int n,x; cin>>n>>x;
  int cn = 0;
  for(int i=n;i>=1;i--){
    dbg(n);
    dbg(i);
    if(x%i==0 && x/i<=n && i<=n){
      cn++;
    }
  }
  cout<<cn<<'\n';
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

