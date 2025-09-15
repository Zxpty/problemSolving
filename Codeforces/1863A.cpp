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
  int n,a,q; cin>>n>>a>>q;
  string s; cin>>s;
  if(n==a){
    cout<<"YES\n";
    return;
  }
  
  // n all subs - a subs online - q - notis
  int cn1 = 0,curr=a;
  for(int i=0;i<q;i++){
    if(s[i]=='+'){
      cn1++;
      curr++;
    }
    else curr--;
    if(curr==n){
      cout<<"YES\n";
      return;
    }
  }
  if(a+cn1>=n){
    cout<<"MAYBE\n";
  }else cout<<"NO\n";


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


