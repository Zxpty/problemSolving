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
	int n = 3;
	vector<int> r(n);
	for(int& x : r) cin >> x;
	sort(r.begin(), r.end());
	int ans = r[2] - r[0];
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			sum += r[j];
		}

		int mx = sum;
		int mn = sum;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			mx = max(mx, r[j]);
			mn = min(mn, r[j]);
		}
		ans = min(ans, mx - mn);
	}
	cout << ans << '\n';
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
