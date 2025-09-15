#include <bits/stdc++.h>
#include <unordered_map>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll MX = 1e6+1;

vector<ll> pre(MX + 1);

void init() {
    pre[0] = 0;
    for (ll i = 1; i <= MX; ++i) {
        pre[i] = pre[i - 1] + i;
    }
}

void solve() {
    ll d;
    cin >> d;
    ll target = d;
    unordered_map<ll, ll> prefix_map;
    vector<pair<ll, ll>> ans;

    for (ll right = 1; right<=MX; right++) {
        ll needed = pre[right] - target;
        if (prefix_map.count(needed)) {
            ans.push_back({ prefix_map[needed], right });
        }
        prefix_map[pre[right]] = right;
    }
    cout << (int)ans.size() << '\n';
    reverse(ans.begin(),ans.end());
    for (auto x : ans) {
        cout << x.first << " " << x.second << '\n';
    }
}

int main() {
    cpu();
    int t = 1;
    init();
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
