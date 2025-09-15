#include <bits/stdc++.h>
#include <iostream>
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
  string x,y; cin>>x>>y;
  int n = (int)x.size();
  int m = (int)y.size();
  int pos = 0;
  for(int i=0;i<n;i++){
    if(x[i]=='?'){
      if(pos<m) x[i]=y[pos++];
      else x[i]='a';
    }else if(x[i]==y[pos])pos++;
  }
  if(pos>=m) cout<<"YES\n"<<x<<'\n';
  else cout<<"NO\n";

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

