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
  string s; cin>>s;
  int q; cin>>q;
  int cn = 0;
  for(int i=0;i+3<(int)s.size();i++){
    if(s.substr(i,4)=="1100"){
      cn++;
    }
  }
  while(q--){
    int x,v;
    cin>>x>>v;
    x--;
    for(int i=max(0,x-3);i<=min((int)s.size()-4,x);i++){
      if(s.substr(i,4)=="1100"){
        cn--;
      }
    }
    s[x] = v+'0';
    for(int i=max(0,x-3);i<=min((int)s.size()-4,x);i++){
      if(s.substr(i,4)=="1100"){
        cn++;
      }
    }
    cout<<(cn>0?"YES":"NO")<<'\n';
  }
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

