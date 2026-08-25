#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MXN = 105;
const int MXW = 100005;

long long dp[MXN][MXW];

void UWU(){
	memset(dp, 0, sizeof(dp));
	int n, w; cin >> n >> w;
	vector<array<int, 2>> item(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> item[i][0] >> item[i][1];
	}

	for(int i = 1; i <= n; i++){
		for(int p = 1; p <= w; p++){
			dp[i][p] = dp[i - 1][p];
			if(p - item[i][0] >= 0) dp[i][p] = max(dp[i][p], dp[i - 1][p - item[i][0]] + item[i][1]);
		}
	}
	cout << dp[n][w];
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
