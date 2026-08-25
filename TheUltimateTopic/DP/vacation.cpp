#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MXN = 100005;
const int MN = -1e9;
long long dp[MXN][3];

void UWU(){
	memset(dp, MN, sizeof(dp));
	int n; cin >> n;
	vector<array<int, 3>> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];
	for(int i = 1; i < n; i++){
		dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = a[i][2] + max(dp[i - 1][1], dp[i - 1][0]);
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

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
