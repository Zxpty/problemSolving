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
  vector<int> a(n),b(n);
  for(int& x : a) cin>>x;
  for(int& x : b) cin>>x;
  for(int i=0;i<n;i++){
    if(a[i]>b[i]) swap(a[i],b[i]);
  }
  int mxa = *max_element(a.begin(),a.end());
  int mxb = *max_element(b.begin(),b.end());
  if(mxa == a.back() && mxb==b.back()){
    cout<<"Yes\n";
  }else cout<<"No\n";
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


