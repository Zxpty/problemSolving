#include <bits/stdc++.h>
#include <queue>

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
	bool ok = 0;
	auto bfs = [&](int node){
		vis[node] = 1;
		queue<int> q;
		q.push(node);
		long long nodos = 0;
		long long aristas = 0;
		while(!q.empty()){
			auto curr = q.front(); q.pop();
			aristas += adj[curr].size();
			nodos++;
			for(auto v : adj[curr]){
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
		return aristas == nodos * (nodos - 1);
	};
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			if(!bfs(i)){
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES";
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
