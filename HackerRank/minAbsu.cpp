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
  sort(r.rbegin(),r.rend());
  dbg(r);
  ll sum = 0;
  for(int i=0;i<n;i++){
    ll op = (((1LL<<i)*r[i])*1LL);
    sum+= op;
    dbg(sum);
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


