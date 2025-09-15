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
  for(int i=0;i<n;i++){
    cout<<2*i+1<<' ';
  }cout<<'\n';

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

