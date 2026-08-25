#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MXR = 1005;
const int MXC = 1005;
const long long MOD = 1e9 + 7;
long long dp[MXR][MXC];

void UWU(){
	memset(dp, 0, sizeof(dp));
	int h, w; cin >> h >> w;
	vector<string> r(h);
	for(auto& x : r) cin >> x;
	dp[0][0] = 1;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(r[i][j] == '#') continue;
			if(i - 1 >= 0 ) {
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= MOD;
			} 
			if(j - 1 >= 0) {
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= MOD;
			} 
		}
	}
	cout << dp[h - 1][w - 1];
	
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
