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
	int n; cin >> n;
	map<pair<int, int>, int> mp;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		mp[{u, v}] = w;
	}
	vector<int> vis(n + 1);
	vector<int> parent(n + 1, -1);
	bool found = false;
	vector<int> cycle;
	function<void(int, int)> dfs = [&](int node, int father){
		vis[node] = 1;
		parent[node] = father;
		for(int v : adj[node]){
			if(found) return;
			if(!vis[v]){
				dfs(v, node);
			}else if(v != father){
				found = true;
				cycle.push_back(v);
				int x = node;
				while(x != v && x != -1){
					cycle.push_back(x);
					x = parent[x];
				}
				cycle.push_back(x);
				reverse(cycle.begin(), cycle.end());
				return;
			}
		}
	};
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i, -1);
			if(found)break;
		}
	}
	int m = n + 1;
	int first = 0;
	for(int i = 0; i < m - 1; i++){
		if(!mp.count({cycle[i], cycle[i + 1]})){
			first += mp[{cycle[i + 1], cycle[i]}];
		}
	}
	reverse(cycle.begin(), cycle.end());
	int second = 0;
	for(int i = 0; i < m - 1; i++){
		if(!mp.count({cycle[i], cycle[i + 1]})){
			second += mp[{cycle[i + 1], cycle[i]}];
		}
	}
	int ans = min(first, second);
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
