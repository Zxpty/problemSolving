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
   int n, t;
   cin >> n >> t;
   int r = n-t;
   while (r > 0)
   {
        r -= 2*t;
   }
   if(r == 0 || r == -t ) cout << 0;
   else
   {
        cout << r+(2*t)<<'\n';
   }
   

}
int main()
{
    cpu();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

