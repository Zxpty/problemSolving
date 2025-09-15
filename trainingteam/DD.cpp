#include <bits/stdc++.h>
#include <string>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int MX = 2*1e5+1;

void solve()
{
  auto check = [&](char x, char y){
    bool ok = false;
    if(x=='4'&& y=='2'){
      ok = true;
    }
    return ok;
  };

  int n; cin>>n;
  string r = "";
  for(int i=1;i<=n;i++){
    r+=to_string(i);
  }
  int cn = 0;
  for(int i=0;i+1<(int)r.size();i++){
    if(check(r[i], r[i+1])){
      cn++;
    }
  }
  cout<<cn<<'\n';

}
int main()
{
    cpu();
    int t = 1;
    //dbg(global);
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

