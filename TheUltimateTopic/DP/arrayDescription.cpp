#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int N = 100005;
const int M = 105;
const int MOD = 1e9 + 7;
int dp[N][M];

void UWU(){
	int n, m; cin >> n >> m;
	vector<int> x(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}

	if(x[1] == 0){
		for(int v = 1; v <= m; v++){
			dp[1][v] = 1;
		}
	}else{
		dp[1][x[1]] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		if(x[i] == 0){
			for(int v = 1; v <= m; v++){
				dp[i][v] = dp[i - 1][v];
				dp[i][v] %= MOD;
				if(v - 1 >= 1) dp[i][v] += dp[i - 1][v - 1];
				dp[i][v] %= MOD;
				if(v + 1 <= m) dp[i][v] += dp[i - 1][v + 1];
				dp[i][v] %= MOD;
			}
		}else{
			dp[i][x[i]] = dp[i - 1][x[i]];
			dp[i][x[i]] %= MOD;
			if(x[i] - 1 >= 1) dp[i][x[i]] += dp[i - 1][x[i] - 1];
			dp[i][x[i]] %= MOD;
			if(x[i] + 1 <= m) dp[i][x[i]] += dp[i - 1][x[i] + 1];
			dp[i][x[i]] %= MOD;
		}
	}

	int ans = 0;
	for(int v = 1; v <= m; v++){
		ans += dp[n][v];
		ans %= MOD;
	}
	cout << ans;
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
