#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;


long long dp[100005];

void UWU(){
	int n, target; cin >> n >> target;
	vector<int> price(n + 1), pages(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> price[i];
	}

	for(int i = 1; i <= n; i++){
		cin >> pages[i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = target; j >= price[i]; j--){
			dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
		}
	}
	cout << dp[target];
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
