#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e5 + 2;

bool dp[MX];

void UWU(){
	int n; cin >> n;
	vector<int> coins(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> coins[i];
	}
	dp[0] = true;
	for(int c : coins){
		for(int j = 100000; j >= c; j--){
			dp[j] = dp[j] | dp[j - c];
		}
	}
	vector<int> ans;
	for(int i = 1; i <= 100000; i++){
		if(dp[i]) ans.push_back(i);
	}
	cout << int(ans.size()) << "\n";
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
