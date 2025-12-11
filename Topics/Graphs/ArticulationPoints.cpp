#include <bits/stdc++.h>
#include <csignal>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
/*
 * Articulation Point: Nodes on whose removal the graph breaks into multiple components
 *
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
	vector<int> vis(N);
	vector<int> time(N);
	vector<int> low(N);
	vector<int> mark(N);
	int timer = 0;
	function<void(int,  int)> dfs =[&](int node, int parent){
		time[node] = low[node] = timer++;
		int child = 0;
		for(auto v : adj[node]){
			if(v == parent) continue;
			if(!vis[v]){
				dfs(v, node);
				low[node] = min(low[node], low[v]);
				if(low[v] >= time[node] and parent != -1){
					mark[node] = 1;
				}
				child++;
			}else{
				low[node] = min(low[node], time[v]);
			}
		}
		if(child > 1 and parent == -1){
			mark[node] = 1;
		}
	};
	for(int i = 0; i < N; i++){
		if(!vis[i]){
			dfs(i, -1);
		}
	}
	vector<int> ans;
	for(int i = 0; i < N; i++){
		if(mark[i] == 1){
			ans.push_back(i);
		}
	}
	if(int(ans.size()) == 0) cout << "-1" << '\n';
	else{
		for(int x : ans){
			cout << x << " ";
		}
	}
	return 0;
}
/*
5 4 
0 1
1 4
4 3
4 2
 * */
