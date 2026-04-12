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
    ll n; cin >> n;
if(n == 1){
	cout << 1 << '\n';
	return;
}
    n *= 2;
    ll k = sqrt(n);
    if(k * (k + 1) > n) k--;
    ll acc = (k * (k + 1)) / 2;
    ll diff = (n / 2) - acc;
    if(diff == 0) {
        diff = k - 1;
        ll g2 = __gcd(diff, k);
        cout << k << ' ' << diff / g2 << '/' << k / g2 << nl;
        return;
    }
    k++;
    diff--;
    ll g = __gcd(diff, k);
    cout << k;
    if(diff > 0) {
        cout << ' ' << diff / g << '/' << k / g;
    }
    cout << nl;
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

