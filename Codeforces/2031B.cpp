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
typedef vector<int> vi;
void solve()
{
  int n; cin>>n;
  vi r(n);
  for(int& x : r) cin>>x;
  for(int i=0;i+1<n;i++){
    if(r[i]==r[i+1]+1)swap(r[i],r[i+1]);
  }
  bool ok = true;
  for(int i=0;i<n;i++){
    if(r[i]!=i+1){
      ok = false;
      break;
    }
  }
  cout<<(ok ? "YES" : "NO")<<'\n';
   
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

