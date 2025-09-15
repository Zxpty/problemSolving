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
  int n,r; cin>>n>>r;
  int rows = 0;
  int alone = 0;
  for(int i=0;i<n;i++){
    int fam; cin>>fam;
    rows+=(fam/2);
    alone+=(fam%2);
  }
  int total = rows+alone;
  while(total>r){
    total-=1;
    alone-=2;
  }
  int ans = (2*rows)+alone;
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

