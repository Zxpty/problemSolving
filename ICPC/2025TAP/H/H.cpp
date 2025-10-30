#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
#define nl '\n';
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

bool isPrime (ll x) {
    if(x == 1) {
        return false;
    }
    if(x == 2) {
        return true;
    }
    if(x % 2 == 0) {
        return false;
    }
    for(int i = 3; i * i <= x; i += 2) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n; cin >> n;
    vector<ll> v(n);
    map<ll, int> mp;
    for(auto &x : v) {
        cin >> x;
        mp[x]++;
    }
    ll ans = 1;
    if(n == 2) {
        if(v[0] == 1) {
            int r = sqrt(v[1]);
            if(r * r == v[1] && isPrime(r)) {
                cout << r << " " << r << nl;
                return;
            }
            if(isPrime(v[1])) {
                cout << 1LL * v[1] * v[1] << " " << 1LL * v[1] * v[1] << nl;
                return;
            }
        }
    }
    sort(all(v));
    for(int i = 0; i < n; i++) {
        if(ans == 1) {
            ans = v[i];
            continue;
        }
        if(ans >= v[i] && ans % v[i] == 0) {
            continue;
        }
        if(__gcd(v[i], ans) != 1) {
            ans *= __gcd(v[i], ans);
        } else {
            ans *= v[i];
        }
    }
    if(ans == 1) {
        cout << '*';
        return;
    }
    int left = -1;
    for(auto x : v) {
        if(x > ans) {
            continue;
        }
        if(mp.find(ans / x) == mp.end()) {
            left = ans / x;
        }
    }
    cout << ans << ' ' << left << nl;
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
