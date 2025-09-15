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
  int n; cin>>n;
  vector<int> r(n);
  for(int& x : r) cin>>x;
  vector<int> y = r;
  sort(y.rbegin(),y.rend());
  dbg(y);
  map<int,int> mp;
  int rank = 1;
  for(int i=0;i<n;i++){
    if(i>0 && y[i]==y[i-1]){
      rank++;
      continue;
    }
    mp[y[i]] = rank++;
  }
  for(int x : r){
    cout<<mp[x]<<' ';
  }
  cout<<'\n';
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

