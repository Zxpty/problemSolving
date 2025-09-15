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
  int n,q; cin>>n>>q;
  vector<ll> r(n);
  for(auto& x : r) cin>>x;
  vector<ll> preSum(n);
  preSum[0] = r[0];
  for(int i=1;i<n;i++){
    preSum[i] = r[i]+preSum[i-1]; 
  }
  auto sum = [&](int l, int r){
    if(l==0) return preSum[r];
    return preSum[r]-preSum[l-1];
  };
  while(q--){
    int l,r; cin>>l>>r;
    l--,r--;
    cout<<sum(l, r)<<'\n';
    }
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

