#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = -1e9+7;

void UWU(){
	int n; cin >> n;
	vector<int> vals(n + 1);
	for(int i = 1; i <= n; i++) cin >> vals[i];

	for(int i = 1; i <=n; i++) if(vals[i] == 0) vals[i] = -1;

	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	vector<int> dp(n + 1);
	vector<int> ans(n + 1);
	function<void(int, int)> dfs = [&](int node, int parent){
		dp[node] = vals[node];
		for(int v : adj[node]){
			if(v != parent){
				dfs(v, node);
				dp[node] += max(0, dp[v]);
			}
		}
	};

	function<void(int, int)> dfs2 = [&](int node, int parent){
		for(int v : adj[node]){
			if(v != parent){
				int calc = ans[node] - max(0, dp[v]);
				ans[v] = dp[v] + max(0, calc);
				dfs2(v, node);
			}
		}
	};

	dfs(1, 0);
	ans[1] = dp[1];
	dfs2(1, 0);

	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
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
