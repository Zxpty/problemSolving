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
  int n,k; cin>>n>>k; // n = shelves // k = bottles
  vector<pair<ll,ll>> b(k);
  for(int i=0;i<k;i++){
    cin>>b[i].first>>b[i].second;
  }
  if(n>=k){
    ll sum = 0;
    for(int i=0;i<k;i++){
      sum+=b[i].second;
    }
    cout<<sum<<'\n';
  }else{
    map<ll,ll> cost;
    for(int i=0;i<k;i++){
      cost[b[i].first]+=b[i].second;
    }
    auto f = [&](const pair<ll,ll>& a, const pair<ll,ll>& b){
      return a.second>b.second;
    };
    vector<pair<ll,ll>> ans(cost.begin(),cost.end());
    sort(ans.begin(),ans.end(),f);
    ll sum = 0;
    for(int i=0;i<min(n,(int)ans.size());i++){
      sum+=ans[i].second;
    }
    cout<<sum<<'\n';
  }
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

