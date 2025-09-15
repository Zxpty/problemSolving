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
  vector<string> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int q; cin>>q;
  vector<string> b(q);
  for(int i=0;i<q;i++){
    cin>>b[i];
  }
  dbg(a,b);
  for(int i=0;i<q;i++){
    int cn = 0;
    for(int j=0;j<n;j++){
      if(b[i]==a[j]){
        cn++;
      }
    }
    cout<<cn<<'\n';
    cn = 0;
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


