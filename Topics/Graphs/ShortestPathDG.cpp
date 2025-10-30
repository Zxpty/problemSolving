#include <bits/stdc++.h>
#include <csignal>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
	cpu();
	int N, M; cin >> N >> M;
	vector<vector<pair<int, int>>> adj(N);
	for(int i = 0; i < M; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}
	vector<int> vis(N);
	stack<int> st;
	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		for(auto it : adj[node]){
			int v = it.first;
			if(!vis[v]) dfs(v);
		}
		st.push(node);
	};

	for(int i = 0; i < N; i++){
		if(!vis[i]){
			dfs(i);
		}
	}

	vector<int> dis(N, 2e9);
	dis[0] = 0;
	while(!st.empty()){
		int node = st.top(); st.pop();
		for(auto it : adj[node]){
			int v = it.first;
			int w = it.second;
			if(dis[node] + w < dis[v]) {
				dis[v] = dis[node] + w;
			}
		}
	}
	vector<int> ans(N);
	for(int i = 0; i < N; i++){
		if(dis[i] == 2e9) ans[i] = -1;
		else ans[i] = dis[i]; 
	}
	for(int x : ans){
		cout << x << " ";
	}
	cout << '\n';
	return 0;
}

/*
4 3
0 1 2
1 2 3
2 3 4
*/

