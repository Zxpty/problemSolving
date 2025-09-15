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
  vector<int> r(3);
  for(int& x : r) cin>>x;
  sort(r.begin(),r.end());
  int small = r[1];
  int sum = 0;
  for(int i=0;i<3;i++){
    sum+=abs(r[i]-small);
  }
  cout<<sum<<'\n';
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

