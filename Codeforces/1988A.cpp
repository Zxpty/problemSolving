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
  int n,k; cin>>n>>k;
  if(n==1){
    cout<<0<<'\n';
    return;
  }
  if(k>n){
    cout<<1<<'\n';
    return;
  }
  cout<<(n-1+k-2)/(k-1)<<'\n';
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

