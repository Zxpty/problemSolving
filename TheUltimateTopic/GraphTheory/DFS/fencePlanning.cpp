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
	map<int, pair<int, int>> mp;
	for(int i = 1; i <=n ;i++){
		int x, y; cin >> x >> y;
		mp[i] = {x, y};
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n + 1);
	vector<vector<int>> componentes;
	function<void(int, vector<int>& )> dfs = [&](int node, vector<int>& comp){
		vis[node] = 1;
		comp.push_back(node);
		for(int v : adj[node]){
			if(!vis[v]){
				dfs(v, comp);
			}
		}
	};
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			vector<int> comp;
			dfs(i, comp);
			componentes.push_back(comp);
			comp.clear();
		}
	}
	long long ans = 2e18;
	for(auto x : componentes){
		int mn_x = 1e9;
		int mx_x = -1e9;
		int mn_y = 1e9;
		int mx_y = -1e9;
		for(int y : x){
			auto [rx, ry] = mp[y];
			mn_x = min(mn_x, rx);
			mx_x = max(mx_x, rx);
			mn_y = min(mn_y, ry);
			mx_y = max(mx_y, ry);
		}
		long long first = mx_x - mn_x;
		long long second = mx_y - mn_y;
		long long calc = 2 * (first + second);
		ans = min(ans, calc);
	}
	cout << ans;
}

int main(){
	cpu();
	int t = 1;
	//read(t);
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	while(t--){
		UWU();
	}
	return 0;
}

