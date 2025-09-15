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
  int n,m; cin>>n>>m;
  vector<bool> x(n+1,true);
  vector<int> r(m);
  vector<int> off(n+1,-1);
  for(int& x : r)cin>>x;
  for(int i=0;i<m;i++){
    int val = r[i];
    while(val<=n && x[val]){
      x[val] = false;
      off[val] = r[i];
      val++;
    }
  }
  for(int i=1;i<=n;i++){
    if(off[i]!=-1){
      cout<<off[i]<<' ';
    }
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

