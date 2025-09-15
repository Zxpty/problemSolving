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
  vi r(n); for(int& x : r) cin>>x;
  int ans = k+1;
  for(int a : r)
    ans = min(ans,(k-a%k)%k);
  if(k==4){
    int even = 0;
    for(int a : r) even+=(a%2==0);
    ans = min(ans,max(0,2-even));
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

