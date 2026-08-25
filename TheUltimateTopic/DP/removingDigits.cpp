#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e6 + 2;

long long dp[MX];

void UWU(){
	memset(dp, MX, sizeof(dp));
	int n; cin >> n;
	for(int i = 1; i <= 9; i++){
		dp[i] = 1;
	}
	for(int i = 10; i < MX; i++){
		vector<int> digits;
		int num = i;
		while(num > 0){
			digits.push_back(num % 10);
			num /= 10;
		}
		for(int x : digits){
			dp[i] = min(dp[i], dp[i - x] + 1);
		}
	}
	cout << dp[n];
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
