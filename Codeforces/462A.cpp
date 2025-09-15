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
int xs[] = {0,0,1,-1};
int ys[] = {1,-1,0,0};
void solve()
{
  int n; cin>>n;
  vector<string> r(n);
  int cn = 0;
  for(auto& x : r) cin>>x;
  dbg(r);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int z = 0;z<4;z++){
        int x = i+xs[z];
        int y = j+ys[z];
        if(x<n && x>=0 && y<n && y>=0 && r[x][y]=='o'){
          dbg(cn);
          cn++;
        }
      }
      if(cn%2!=0){
        cout<<"NO\n";
        return;
      }
    }
  }
  cout<<"YES\n";
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

