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
  ll a,b,c,d; cin>>a>>b>>c>>d;
  ll mn = min({a,c,d});
  if(mn==a){
    cout<<256*1LL*mn<<'\n';
  }else{
    a-=mn;
    ll op = min(a,b);
    dbg(op);
    cout<<256*1LL*mn+32*op<<'\n';
  }
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

