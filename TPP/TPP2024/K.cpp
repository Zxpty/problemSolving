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
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n);

	int mx = 0;
	int cn = 0;

	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		cn++;
		for(int v : adj[node]){
			if(!vis[v]){
				dfs(v);
			}
		}
	};

	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i);
			mx = max(mx, cn);
			cn = 0;
		}
	}
	cout << mx << '\n';
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
