#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MOD = 1e9+7;
long long dp[100005];

void UWU(){
	int t, k; cin >> t >> k;
	dp[0] = 1;
	for(int i = 1; i <= 100000; i++){
		dp[i] = dp[i - 1];
		if(i - k >= 0) dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
	}

	vector<int> pre(100005);
	pre[0] = dp[0];
	for(int i = 1; i <= 100000; i++){
		pre[i] = (pre[i - 1] + dp[i]) % MOD;
	}

	for(int i = 0; i < t; i++){
		int a, b; cin >> a >> b;
		int ans = (pre[b] - pre[a - 1] + MOD) % MOD;
		cout << ans << "\n";
	}

	
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
