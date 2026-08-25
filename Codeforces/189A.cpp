#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 4005;

long long dp[MX];

void UWU(){
	for(int i = 0; i < MX; i++) dp[i] = -100005;
	int n, a, b, c; cin >> n >> a >> b >> c;

	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		if(i - a >= 0) dp[i] = max(dp[i], dp[i - a] + 1);
		if(i - b >= 0) dp[i] = max(dp[i], dp[i - b] + 1);
		if(i - c >= 0) dp[i] = max(dp[i], dp[i - c] + 1);
	}
	cout << max(dp[n], 1LL);
	
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
