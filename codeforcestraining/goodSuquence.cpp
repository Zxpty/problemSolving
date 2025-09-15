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
  vi r(n);
  for(int& x : r) cin>>x;
  map<int,int> mp;
  for(int x : r) mp[x]++;
  dbg(mp);
  int mn = 0;
  for(auto&[first,second] : mp){
    if(second<first){
      mn+=second;
    }else mn+=second-first;
  }
  cout<<mn<<'\n';
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

