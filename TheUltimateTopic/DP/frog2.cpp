#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MXN = 100005;
const int INF = 1e9 + 7;
long long dp[MXN];

void UWU(){
	memset(dp, INF, sizeof(dp));
	int n, k; cin >> n >> k;
	vector<int> h(n);
	for(int i = 0; i < n; i++) cin >> h[i];
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	for(int i = 2; i < n; i++){
		for(int j = 1; j <= k; j++){
			if(i - j < 0) continue;
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
	}
	cout << dp[n - 1];
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
