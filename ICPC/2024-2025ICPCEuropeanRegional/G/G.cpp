#include <bits/stdc++.h>
#include <vector>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
void solve()
{
	ll r, n; cin >> r >> n;
	vector<ll> v(n);
	for(auto &x : v) cin >> x;
	ll ans = 0;
	ll maxD = r;
	bool cond = false;
	ll minD = 0;
	for(int i = 0; i < n; i++) {
		ans += v[i];
		if(ans < 0 || ans >= maxD) {
			cond = true;
		}
		ans = min(maxD, ans);
		ans = max(minD, ans);
	}
	if(cond) {
		cout << ans;
	} else {
		cout << "uncertain";
	}
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


