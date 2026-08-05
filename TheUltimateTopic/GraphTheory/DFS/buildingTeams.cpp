#include <bits/stdc++.h>
#include <cstdlib>

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
	vector<int> color(n + 1);
	function<void(int, int)> dfs = [&](int node, int col){
		vis[node] = 1;
		color[node] = col;
		for(int v : adj[node]){
			if(!vis[v]){
				if(col == 1){
					dfs(v, 2);
				}else dfs(v, 1);
			}else{
				if(color[v] == col){
					cout << "IMPOSSIBLE";
					exit(0);
				}
			}
		}
	};
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i, 1);
		}
	}
	for(int i = 1; i <= n; i++){
		cout << color[i] << " ";
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
