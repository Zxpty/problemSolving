#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1002;

long long dp[MX][MX];

void UWU(){
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int i = n, j = m;
	vector<int> ans;
	while(i > 0 && j > 0){
		if(a[i - 1] == b[j - 1]){
			ans.push_back(a[i - 1]);
			i--;
			j--;
		}else{
			if(dp[i - 1][j] > dp[i][j - 1]){
				i--;
			}else{
				j--;
			}
		}
	}
	cout << int(ans.size()) << '\n';
	reverse(ans.begin(), ans.end());
	for(int x : ans){
		cout << x << " ";
	}
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
