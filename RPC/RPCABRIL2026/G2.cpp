#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
#define nl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef int64_t i64;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll mod = 1e9+7;
void solve()
{
    ll p, q; cin >> p >> q;
    for(ll i = 1; i <= 1e6; i++) {
        ll dis = 4LL * (i * i) * (q * q) + (4LL * (i * q * p)) + (p * p) - (8LL * p * q * i * i);
        ll sq = sqrtl(dis);
        if(sq * sq == dis && dis >= 0) {
            if(((2 * i * q) + p + sq) % (2 * p) == 0) {
                ll k = ((2LL * i * q) + p + sq) / (2 * p);
                ll g = k - i;
                if(g >= i) {
                    cout << i << ' ' << k - i << nl;
                    return;
                }
            } else if (((2 * i * q) + p - sq) >= 0 && ((2 * i * q) + p - sq) % (2 * p) == 0) {
                ll r2 = ((2 * i * q) + p - sq) / (2 * p);
                ll g = r2 - i;
                if(g >= i) {
                    cout << i << ' ' << r2 - i << nl;
                    return;
                }
            }
        }
    }
    cout << "impossible" << nl;
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
