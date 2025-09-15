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
  for(int& i : r) cin>>i;
  sort(r.begin(),r.end());
  vector<int> prefSum(n+1);
  prefSum[0] = r[0];
  for(int i=1;i<=n;i++){
    prefSum[i] = prefSum[i-1]+r[i];
  }
  int mx = r[n-1]; // 20
  int cn = 0;
  for(int i=0;i<n;i++){
    if(prefSum[i]<=20)cn++;
  }
  cout<<cn;

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


