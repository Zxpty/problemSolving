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
  vector<int> r(n);
  vector<pair<int,int>> mnx;
  for(int& x : r) cin>>x;
  for(int i=0;i<n;i++){
    int sum = 0;
    for(int j=0;j<r[i];j++){
      int num; cin>>num;
      sum+=num;
    }
    mnx.push_back({sum,r[i]});
  }
  int mn_ans = INT_MAX;
  for(const auto x : mnx){
    int op = (x.first*5)+(x.second*15);
    mn_ans = min(mn_ans,op);
  }
  cout<<mn_ans<<'\n';
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

