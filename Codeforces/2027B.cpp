#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
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
  for(int& x : r) cin>>x;
  int ans =  INT_MAX;
  for(int i=0;i<n;i++){
    int cnMen = 0, cnMay =0;
    int point = r[i];
    for(int k=0;k<i;k++){
      if(point>r[k])cnMen++;
    }
    for(int l=i;l<n;l++){
      if(point<r[l])cnMay++;
    }
    ans = min(ans,(cnMen+cnMay));
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

