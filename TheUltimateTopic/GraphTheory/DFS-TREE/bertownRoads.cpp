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
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n + 1);
	vector<int> tin(n + 1), low(n + 1);
	vector<pair<int, int>> ans;
	int timer = 0;
	bool ok = 0;
	vector<int> parent(n + 1);
	function<void(int, int)> dfs = [&](int node, int parent){
		vis[node] = 1;
		tin[node] = low[node] = ++timer;

		for(int v : adj[node]){
			if(v == parent) continue;
			if(vis[v]){
				if(tin[v] < tin[node]){
					ans.push_back({node, v});
					low[node] = min(low[node], tin[v]);
				}
			}else{
				ans.push_back({node, v});
				dfs(v, node);
				low[node] = min(low[node], low[v]);
				if(low[v] > tin[node]){
					ok = 1;
				}
			}
		}
	};

	dfs(1, 0);
	if(ok){
		cout << 0 << '\n';
		return;
	}

	for(auto [u, v] : ans){
		cout << u << " " << v << '\n';
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
