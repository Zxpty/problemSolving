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
  auto asx = [&](ll x){
    if(x<10){
      return x;
    }
    string num = to_string(x);
    ll sz = (ll)num.size();
    return (num[sz-1] - '0')*1LL;
  };
  ll sum = 0;
  for(int i = 1; i <= (2*n)-1; i += 2){
    sum += asx(i);
    dbg(sum);
  }
  cout << sum << '\n';
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


