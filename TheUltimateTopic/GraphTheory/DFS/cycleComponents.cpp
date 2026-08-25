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
	vector<set<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	vector<int> vis(n + 1);
	bool ok = 0;
	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		if(int(adj[node].size()) != 2) ok = 1;
		for(int v : adj[node]){
			if(!vis[v]){
				dfs(v);
			}
		}
	};
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
			if(!ok){
				ans++;
			}
			ok = 0;
		}
	}
	cout << ans << '\n';
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
