#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

void solve()
{
    int x; cin >> x;
    int exp = 0;
    int n = x;
    while(n != 0) {
        n /= 2;
        exp++;
    }
    int diff = x - (1 << (exp - 1));
    cout << diff * 2 << '\n';
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
