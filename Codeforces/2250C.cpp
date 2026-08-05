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
	int n; cin >> n;
	vector<int> l(n), r(n), u(n), v(n);
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i] >> u[i] >> v[i];
	}
	int ans = 0;
	for(int m = 1; m <= n; m++){
		int start = 0;
		for(int i = 0; i < n; i++){
			int left = start + 1;
			int right = m - left + 1;
			if(l[i] <= left && left <= r[i]) continue;
			if(u[i] <= right && right <= v[i]) continue;
			start++;
		}
		if(m <= start) ans = m;
	}
	cout << ans << "\n";
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
