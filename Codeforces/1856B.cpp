#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;
void solve()
{
  int n; cin>>n;
  vector<ll> r(n);
  for(ll& x : r) cin>>x;
  if(n==1){cout<<"NO\n"; return;}
  ll sum = 0;
  ll mn = 0;
  for(int i=0;i<n;i++){
    sum+=r[i];
    mn+=r[i]== 1 ? 2 : 1;
  }
  cout<<(mn>sum?"NO":"YES")<<'\n';
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

