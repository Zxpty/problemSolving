#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
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
  // n = members , k = opinions
  int ans = n;
  vector<string> x(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
    if(x[i]!=x[0]){
      ans--;
    }
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


