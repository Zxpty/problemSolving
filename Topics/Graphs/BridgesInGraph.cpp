#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
/*
 * Definition: is a cut in the graph that make the division of one component into two or more components
 * commom questions: Print all the bridges
 * implementation:
 * Tim[] = dfs time insertion
 * low[] = min lowest time insertion of all adjacanets nodes apart from the parent
 * To implement we need to use the Tarjan's Algorithm
*/
int main() {
	cpu();
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N);
	for(int i = 0; i < M; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> time(N);
	vector<int> low(N);
	vector<int> vis(N);
	vector<vector<int>> bridges;
	int timer = 0;
	function<void(int, int)> dfs = [&](int node, int parent){
		vis[node] = 1;
		time[node] = low[node] = timer++;
		for(auto v : adj[node]){
			if(v == parent) continue;
			if(!vis[v]){
				dfs(v, node);
				low[node] = min(low[node], low[v]);
				if(low[v] > time[node]){
					bridges.push_back({v, node});
				}
			}else{
				low[node] = min(low[node], low[v]);
			}
		}
	};
	dfs(0, -1);
	for(auto e : bridges){
		int from = e[0];
		int to = e[1];
		cout << from << " " << to << "\n";
	}
	return 0;
}
/*
4 4
0 1
1 2
2 0
1 3

*/
