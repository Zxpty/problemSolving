#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e6 + 1;
const int MOD = 1e9 + 7;

long long dp[MX];

void UWU(){
	int n, x; cin >> n >> x;
	vector<int> coins(n);
	for(int& x : coins) cin >> x;
	dp[0] = 1;

	for(int c : coins){
		for(int i = 1; i <= x; i++){
			if(i - c >= 0) dp[i] = (dp[i] + dp[i - c]) % MOD;
		}
	}
	cout << dp[x];
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
