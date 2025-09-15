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
  int left = 0;
  int mx = 0;
  while(left<n){
    int right = left+1;
    int cn = 0;
    while(right+1<n && r[right]-r[left]){
      right++;
      cn++;
    }
    mx = max(mx,cn);
    left = right;
  }
  dbg(mx);

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


