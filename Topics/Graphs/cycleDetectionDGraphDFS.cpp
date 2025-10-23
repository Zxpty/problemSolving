#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
	cpu();
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	vector<int> vis(N);
	vector<int> path(N);
	for(int i = 0; i < M; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	bool check = 0;
	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		path[node] = 1;
		for(auto v : adj[node]){
			if(!vis[v]) dfs(v);
			else if(path[v]){
				check = 1;
			}
		}
		path[node] = 0;
	};
	for(int i = 0; i < N; i++){
		if(!vis[i]){
			dfs(i);
			if(check){
				cout << "The directed Graph has a cycle" << '\n';
				return 0;
			}
		}
	}
	cout << "The graph is DAG and have TopoSort" << '\n';
	return 0;
}

/*

3 3
0 1
1 2
2 0

*/

