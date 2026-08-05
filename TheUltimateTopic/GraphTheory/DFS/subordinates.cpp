#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

void UWU(){
	int n; cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 2; i <= n; i++){
		int node; cin >> node;
		adj[node].push_back(i);
	}

	vector<int> dp(n + 1, 1);
	function<void(int, int)> dfs = [&](int node, int parent){
		for(int v : adj[node]){
			dfs(v, node);
			dp[node] += dp[v];
		}
	};

	dfs(1, -1);
	for(int i = 1; i <= n; i++){
		cout << dp[i] - 1 << ' ';
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
