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
  int l = 0;
  string x;
  while(l<n){
    int r = l;
    while(r<n && s[r]==s[l])r++;
    x.push_back(s[l]);
    l = r;
  }
  int m = (int)x.size();
  //dbg(x);
  vector<int> p(2);
  for(int i=0;i<m;i++){
    p[x[i]-'0']++;
  }
  if(p[1]>p[0]){
    cout<<"YES\n";
  }else if(p[1]==p[0]){
    if(x[0]=='0' && x[m-1]=='1' && m>2){
      cout<<"YES\n";
    }else cout<<"NO\n";
  }else cout<<"NO\n";
  
  //dbg(x);
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

