#include <algorithm>
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
const int MX = 50+1;
void solve()
{
  int n; cin>>n;
  vector<int> r(n);
  for(int& x : r) cin>>x;
  /*bool ok = true;
  for(int i=0;i+1<n;i++){
    if(r[i]<r[i+1]){
      ok = false;
      break;
    }
  }*/
  /*if(ok){
    cout<<n-1<<'\n';
  }else{*/
    vector<int> p(n+1,0);
    for(int x : r) p[x]++;
    int mx = *max_element(p.begin(),p.end());
    vector<int> a(n,1);
    for(int i=1;i<n;i++){
      if(r[i]>=r[i-1]){
        a[i] = a[i-1]+1;
      }
    }
    int mx_conse = *max_element(a.begin(),a.end());
    cout<<min(n-mx,n-mx_conse)<<'\n';
  //}
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

