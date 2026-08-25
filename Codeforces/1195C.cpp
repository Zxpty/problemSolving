#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 100005;

long long dp[MX][2];

void UWU(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;

	dp[0][0] = a[0];
	dp[0][1] = b[0];

	for(int i = 1; i < n; i++){
		dp[i][0] = dp[i - 1][0];
		dp[i][0] = max(dp[i][0], dp[i - 1][1] + a[i]);

		dp[i][1] = dp[i - 1][1];
		dp[i][1] = max(dp[i][1], dp[i - 1][0] + b[i]);
	}
	long long mx = max(dp[n - 1][0], dp[n - 1][1]);
	cout << mx;
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
