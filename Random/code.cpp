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
  ll n,k; cin>>n>>k;
  vector<ll> r(n);
  for(ll& x : r) cin>>x;
  sort(r.begin(),r.end());
  if(n==1){
    if(r[0]<=k){
      cout<<"YES";
      return;
    }else{
      cout<<"NO";
      return;
    }
  }
  ll t_time = 0;
  if(n>3){
    ll faster = r[1] + r[1] + r[0] + r[n-1];
    ll lower = r[0] + r[1] + r[n-2] + r[n-1];
    t_time+= min(faster,lower);
    n-=2;
  }
  if(n==3){
    t_time+=r[2]+r[1]+r[0];
  }else if(n==2){
    t_time+= r[1];
  }
  //dbg(t_time);
  if(t_time<=k){
    cout<<"YES";
  }else{
    cout<<"NO";
  }
}
int main()
{
    cpu();
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++){
      cout<<"Case #"<<i<<": ";
      solve();
      cout<<'\n';
    }
    return 0;
}


