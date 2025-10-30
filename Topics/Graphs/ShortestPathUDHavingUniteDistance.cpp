#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
	cpu();
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	for(int i = 0; i < M; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> dis(N, 1e9);
	dis[1] = 0;
	queue<int> q;
	q.push(1);

	while(!q.empty()){
		int node = q.front(); q.pop();
		for(int v : adj[node]){
			if(dis[node] + 1 < dis[v]){
				dis[v] = dis[node] + 1;
				q.push(v);
			}
		}
	}
	for(int i = 0; i < N; i++){
		cout << dis[i] << " ";
	}
	
	return 0;
}

/*
5 4
0 1
1 2
2 3
3 4
*/
