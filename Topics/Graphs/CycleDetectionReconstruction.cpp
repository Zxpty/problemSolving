#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
	cpu();
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	for(int i = 0; i < N; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(N);
	vector<int> Parent(N, -1);
	bool found = false;
	vector<int> cycle;
	function<void(int, int)> dfs = [&](int node, int parent){
		vis[node] = 1;
		Parent[node] = parent;
		for(int v : adj[node]){
			if(found) return;
			if(!vis[v]){
				dfs(v, node);
			}else if(v != parent){
				found = true;
				cycle.push_back(v);
				int x = node;
				while(x != v && x != -1){
					cycle.push_back(x);
					x = Parent[x];
				}
				cycle.push_back(v);
				reverse(cycle.begin(), cycle.end());
				return;
			}
		}
	};
	for(int i = 0; i < N; i++){
		if(!vis[i]){
			dfs(i, -1);
			if(found) break;
		}
	}
	if(found){
		for(int x : cycle) cout << x << " ";
	}else{
		cout << "There isn't a cycle in the graph\n";
	}
	return 0;
}
/*
4 4
0 1
0 2 
1 2
2 3

*/

