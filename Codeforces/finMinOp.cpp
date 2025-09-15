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
  if(k==1){
    cout<<n<<'\n';
    return;
  }
  int ans = 0;
  while(n){
    dbg(n%k);
    ans+=n%k;
    dbg(ans);
    n/=k;
    dbg(n/=k);
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


