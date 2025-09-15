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
  int k; cin>>k;
  string s; cin>>s;
  int n = (int)s.size();

  if(k==2){
    string a,b;
    int cn1 = 0, cn2 =0;
    for(int i=0;i<n;i++){
      a+=(i%2==0) ? '0' : '1';
      b+=(i%2==0) ? '1' : '0';
    }
    for(int i=0;i<n;i++){
      if(s[i]!=a[i])cn1++;
      if(s[i]!=b[i])cn2++;
    }
    if(cn1<=cn2){
      cout<<cn1<<' '<<a<<'\n';
    }else cout<<cn2<<' '<<b<<'\n';
  }else{
    int left = 0;
    int ans = 0;
    while(left<n){
      int right = left;
      int cn = 0;
      bool ok = false;
      while(right<n && s[left]==s[right]){
        cn++;
        right++;
        if (cn%k==0) {
          if (right < n && s[right] == s[left]) {
               s[right - 1] = (s[right - 1] == '0') ? '1' : '0';
          } else {
               s[right - 2] = (s[right - 2] == '0') ? '1' : '0';
          }
               ans++;
               break;
          }
      }
      left = right;
      dbg(s);
      dbg(left);
      dbg(right);
    }
    cout<<ans<<' '<<s<<'\n';
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

