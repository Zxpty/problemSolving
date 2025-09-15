#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;
void solve()
{
  int n; cin>>n;
  vector<int> r(n);
  for(int& x : r) cin>>x;
  vector<pair<int,int>> p(n);
  for(int i=0;i<n;i++)
    p[i] = {r[i],i+1};
  dbg(p);
  vector<int> ans(n);
  for(auto[x,y] : p){
    ans[x-1] = y;
  }
  for(int x : ans){
    cout<<x<<' ';
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

