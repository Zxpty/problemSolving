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
  auto f =[&](const int a, const int b){
    if((a%2!=0)&&(b%2==0)) return true;
    if((a%2==0)&&(b%2!=0)) return false;
    return a<b;
  };
  int n; cin>>n;
  vector<int> r(n);
  for(int& x : r) cin>>x;
  sort(r.begin(),r.end(),f);
  dbg(r);

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

