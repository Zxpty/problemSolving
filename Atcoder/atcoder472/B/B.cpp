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
	vector<int> r(n);
	for(int& x : r) cin >> x;

	int acc = accumulate(r.begin(), r.end(), 0);
	int sum = 0;
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		sum += r[i];
		int calc = abs(sum - (acc - sum));
		ans = min(ans, calc);
	}
	cout << ans << '\n';
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
