#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
void solve()
{
  ll n,k; cin>>n>>k;
  string s; cin>>s;
  ll sum = 0;
  int i = 0;
  while(i<n){
    if(s[i]=='B'){
      sum++;
      i+=k;
    }else i++;
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


