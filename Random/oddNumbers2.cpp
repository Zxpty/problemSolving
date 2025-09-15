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
  ll n; cin>>n;
  ll repeat = n/5;
  ll remain = n%5;
  ll sum = repeat*25;
  vector<int> nums = {1,3,5,7,9};
  for(int i=0;i<remain;i++){
    sum+= nums[i];
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


