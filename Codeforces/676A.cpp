#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int MX = 1e2+1;
void solve()
{
  int n; cin>>n;
  int mn = MX;
  int pos_mn = 0;
  int mx = -1;
  int pos_mx = 0;
  vector<int> r(n);
  for(int& x : r) cin>>x;
  for(int i=0;i<n;i++){
    if(r[i]>mx){
      mx = r[i];
      pos_mx =i+1;
    }
    if(r[i]<mn){
      mn = r[i];
      pos_mn = i+1;
    }
  }
  int ans = abs(pos_mx-pos_mn);
  ans = max(ans,max(abs(pos_mx-n),abs(pos_mx-1)));
  ans = max(ans,max(abs(pos_mn-n),abs(pos_mn-1)));
  cout<<ans<<'\n';
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

