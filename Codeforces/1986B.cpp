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
  string s; cin>>s;
  map<string,int> mp;
  for(int i=0;i<n-1;i++){
    string x = s.substr(i,2);
    mp[x]++;
  }
  int mx = 0;
  string ans;
  for(auto[first,second]: mp){
    if(mx<=second){
      mx = second;
      ans = first;
    }
  }
  cout<<ans<<'\n';
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

