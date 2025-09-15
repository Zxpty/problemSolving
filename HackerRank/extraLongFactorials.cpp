#include <bits/stdc++.h>
#include <fstream>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
typedef int64_t i64;
const ll mod = 1e9+7;

void solve()
{
  int n; cin>>n;
  vector<ll> r(n);
  for(auto& x : r) cin>>x;
  int cor,limit; cin>>cor>>limit;
  dbg(r);
  sort(r.rbegin(),r.rend());
  ll cn = 0;
  ll sum = 0;
  for(int i=0;i<n;i++){
    if(r[i]%cor==0){
      if(cn<limit){
        sum+=r[i]/cor;
        dbg(sum);
        cn++;
      }else{
        sum+=r[i];
        dbg(sum);
      }
    }else{
      sum+=r[i];
      dbg(sum);
    }
  }
  cout<<sum;
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


