#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

void UWU(){
	int n, k; cin >> n >> k;
	vector<double> r(n);
	for(auto& x : r) cin >> x;
	vector<double> pre(n + 1);
	for(int i = 0; i < n; i++){
		pre[i + 1] = pre[i] + r[i];
	}
	double ans = 0;
	for(int i = 0; i <= n - k; i++){
		ans += (pre[i + k] - pre[i]) / (n - k + 1);
	}
	cout << fixed << setprecision(6) << ans << '\n';
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
