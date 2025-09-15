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
  int a,b; cin>>a>>b;
  int optimal = (a+b+1)/2;
  int rest1 = abs(optimal-a);
  int rest2 = abs(optimal-b);
  int sm1=0,sm2=0;
  for(int i=1;i<=rest1;i++){
    sm1+=i;
  }
  for(int i=1;i<=rest2;i++){
    sm2+=i;
  }
  int ans = sm1+sm2;
  dbg(rest1,rest2);
  dbg(ans);
  cout<<ans;
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


