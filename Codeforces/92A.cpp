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
  string s; cin>>s;
  int l = 0;
  int cn =0;
  for(int i=0;i<n;i++){
    if(s[i]=='W')cn++;
  }
  if(cn==n){
    cout<<"0";
    return;
  }


  vector<int> rx;
  while(l<n){
    int r = l;
    int ans = 0;
    while(r<n && s[r]==s[l] && s[r]=='B'){
      if(s[r]=='B')ans++;
      r++;
    }
    if(ans>0)rx.push_back(ans);
    l = r;
  }
  cout<<rx.size()<<'\n';
  for(int x : rx) cout<<x<<' ';
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

