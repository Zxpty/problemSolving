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
  int n;cin>>n;
  int ans = 0;
  ll mul = 1;
  string x = to_string(n);
  for(int i=0;i<x.size();i++){
    int cn = 0;
    for(int a=0;a<=x[i]-'0';a++){
      for(int b=0;b<=x[i]-'0';b++){
        int c = x[i]-'0'-a-b;
        if(c>=0){
          cn++;
        }
      }
    }
    mul*=1LL*cn;
  }
  cout<<mul<<'\n';
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

