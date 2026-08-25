#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MXN = 3005;

long long dp[MXN][MXN];



void UWU(){
	memset(dp, 0, sizeof(dp));
	string s, t; cin >> s >> t;
	int n = int(s.size());
	int m = int(t.size());

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i - 1] == t[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}


	int i = n, j = m;
	string ans = "";
	while(i > 0 && j > 0){
		if(s[i - 1] == t[j - 1]){
			ans += s[i - 1];
			i--;
			j--;
		}else {
			if(dp[i - 1][j] > dp[i][j - 1]){
				i--;
			}else{
				j--;
			}
		}
	}
	reverse(ans.begin(), ans.end());
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
