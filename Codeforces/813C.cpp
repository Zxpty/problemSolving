#include <algorithm>
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
	int n, x; cin >> n >> x;
	vector<vector<int>> adj(n + 1);
	vector<int> parent(n + 1);
	vector<int> depth(n + 1);
	vector<int> maxDepth(n + 1);

	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	function<void(int, int)> dfs = [&](int node, int p){
		maxDepth[node] = depth[node];
		parent[node] = p;
		for(auto v : adj[node]){
			if(v != p){
				depth[v] = depth[node] + 1;
				dfs(v, node);
				maxDepth[node] = max(maxDepth[node], maxDepth[v]);
			}
		}
	};
	dfs(1, -1);

	int moves = 0;
	int ans = 0;
	int node = x;
	//cout << maxDepth[node] << '\n';
	while(node != -1){
		if(depth[node] <= moves){
			break;
		}
		ans = max(ans, 2 * maxDepth[node]);
		node = parent[node];
		moves++;
	}
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
