#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e6 + 2;
const int INF = 1e6 + 7;

long long dp[MX];

void UWU(){
	fill(dp, dp + MX, INF);
	int n, x; cin >> n >> x;
	vector<int> coins(n);
	for(int& x : coins) cin >> x;

	dp[0] = 0;
	for(int i = 1; i <= x; i++){
		for(int c : coins){
			if(i - c >= 0){
				dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
	}
	if(dp[x] == INF) cout << -1;
	else cout << dp[x];
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
