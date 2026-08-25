#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e6 + 2;
const int MOD = 1e9 + 7;
long long dp[MX];

void UWU(){
	int n; cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i < MX; i++){
		for(int coin = 1; coin <= 6; coin++){
			if(i - coin >= 0) dp[i] = (dp[i] + dp[i - coin]) % MOD;
		}
	}
	cout << dp[n];
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
