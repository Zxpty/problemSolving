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
  int n,target; cin>>n>>target;
  if(n==1){
    cout<<"1\n1\n";
    return;
  }
  if(target==1||target==n){cout<<"-1\n";return;}
  int x = target - target%2;
  int y = target + 1 +target%2;
  cout<<"3\n1"<<" "<<x<<" "<<y<<'\n';

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

