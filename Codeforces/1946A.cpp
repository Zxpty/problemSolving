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
  vi r(n);
  for(int& x : r) cin>>x;
  sort(r.begin(),r.end());
  int med = (n-1) / 2;
  int cn = 0;
  for(int i = med; i < n; i++){
    if(r[i]==r[med]) cn++;
  }cout<<cn<<'\n';
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

