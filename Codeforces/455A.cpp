#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 100005;

long long dp[MX];
long long cnt[MX];

void UWU(){
	memset(dp, 0, sizeof(dp));
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		cnt[x]++;
	}
	dp[1] = 1 * cnt[1];
	for(int i = 1; i < MX; i++){
		dp[i] = max(dp[i - 1], dp[i - 2] + (i * cnt[i]));
	}
	long long ans = 0;
	for(int i = 1; i < MX; i++){
		ans = max(ans, dp[i]);
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
