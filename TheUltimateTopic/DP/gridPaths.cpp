#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1005;
const int INF = -1e9 + 7; 
const int MOD = 1e9 + 7;
int dp[MX][MX];

void UWU(){
	int n; cin >> n;
	vector<string> grid(n);
	for(string& s : grid) cin >> s;

	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i - 1 >= 0) dp[i][j] += dp[i - 1][j];
			if(j - 1 >= 0) dp[i][j] += dp[i][j - 1];
			dp[i][j] %= MOD;
			if(grid[i][j] == '*'){
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[n - 1][n - 1];

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
