#include <bits/stdc++.h>
#include <csignal>
#include <functional>
#include <queue>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
/*
 * algorithm that helps to create the minimum spanning tree
 * We need a priority_queue
 * vis array
*/
int main() {
	cpu();
	int N, M; cin >> N >> M;
	vector<vector<pair<int, int>>> adj(N);
	for(int i = 0; i < M; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	vector<int> vis(N);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, 0});
	int sum = 0;
	while(!pq.empty()){
		auto [wt, node] = pq.top(); pq.pop();
		if(vis[node]) continue;
		sum += wt;
		vis[node] = 1;
		for(auto [v, w] : adj[node]){
			if(vis[v])continue;
			pq.push({w, v});
		}
	}
	cout << sum << '\n';
	return 0;
}

