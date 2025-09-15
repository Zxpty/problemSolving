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
  int n; cin>>n;
  vector<ll> r(n);
  for(ll& x : r) cin>>x;
  ll preSum = 0;
  map<ll,int> cn;
  cn[0]=-1;
  int cn_zero = 0;
  int ini_pos = -1;
  for(int i=0;i<n;i++){
    preSum+=r[i];
    if(cn.count(preSum)>0){
      int pos = cn[preSum];
      if(pos>=ini_pos){
        cn_zero++;
        ini_pos = i;
      }
    }
    cn[preSum] = i;
  }
  cout<<cn_zero<<'\n';
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


