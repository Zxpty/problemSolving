#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;
bool dp[505][505];
void UWU(){
	dp[0][0] = 1;
	int n, k; cin >> n >> k;
	vector<int> coins(n);
	for(int& x : coins) cin >> x;

	for(int c : coins){
		for(int j = k; j >= c; j--){
			for(int x = j; x >= 0; x--){
				dp[j][x] |= dp[j - c][x];
				if(x >= c){
					dp[j][x] |= dp[j - c][x - c];
				}
			}
		}
	}
	vector<int> ans;
	for(int x = 0; x <= k; x++){
		if(dp[k][x]) ans.push_back(x);
	}

	cout << ans.size() << '\n';
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
