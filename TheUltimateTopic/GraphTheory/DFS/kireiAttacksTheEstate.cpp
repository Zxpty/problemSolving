#include <algorithm>
#include <bits/stdc++.h>
#include <execution>

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
	vector<int> vals(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> vals[i];
	}
	int m = n - 1;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<long long> max_dp(n + 1), min_dp(n + 1);
	function<void(int, int)> dfs = [&](int node, int parent) {
		if(parent == 0){
			max_dp[node] = vals[node];
			min_dp[node] = vals[node];
		}else{
			max_dp[node] = max(1LL * vals[node], vals[node] - min_dp[parent]);
			min_dp[node] = min(1LL * vals[node], vals[node] - max_dp[parent]);
		}
		for(int v : adj[node]){
			if(v != parent){
				dfs(v, node);
			}
		}
	};
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		cout << max_dp[i] << " ";
	}
	cout << endl;

}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
