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
  vector<int> r = {-2,-3,4,-1,-2,1,5,-3};
  int n = 8;
  int mx = 0;
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      int sum = 0;
      for(int k = i; k<j;k++){
        sum+=r[k];
      }
      mx = max(mx,sum);
    }
  }
  cout<<mx;
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


