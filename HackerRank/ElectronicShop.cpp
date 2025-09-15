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
  int b,n,m; cin>>b>>n>>m;
  vector<int> k(n),d(m);
  for(int& x : k) cin>>x;
  for(int& x : d) cin>>x;
  sort(k.begin(),k.end());
  sort(d.begin(),d.end());
  int i = 0;
  int j = m-1;
  int mxsum = -1;
  while(i<n && j>=0){
    int sum = k[i] + d[j];
    if(sum<=b){
      mxsum = max(mxsum,sum);
      i++;
    }else{
      j--;
    }
  }
  cout<<mxsum;
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


