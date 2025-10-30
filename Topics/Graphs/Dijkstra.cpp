#include <bits/stdc++.h>
#include <queue>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
const long long inf = 1e18;
// only dijkstra is applied when not exits cylces with sum < 0
int main() {
	cpu();
	int N, M; cin >> N >> M;
	vector<vector<pair<int, long long>>> adj(N + 1);
	for(int i = 0; i < M; i++){
		 int u, v; cin >> u >> v;
		 long long w; cin >> w;
		 adj[u].emplace_back(v, w);
	}
	vector<long long> dis(N + 1, inf);
	pqg<pair<long long, int>> pq;
	dis[1] = 0;
	pq.push({0LL, 1});
	while(!pq.empty()){
		auto [d, node] = pq.top(); pq.pop();
		if(dis[node] != d) continue;
		for(auto [v, w] : adj[node]){
			if(d + w < dis[v]){
				dis[v] = d + w;
				pq.push({dis[v], v});
			}
		}
	}
	for(int u = 1; u <= N; u++){
		cout << dis[u] << " ";
	}
	cout << '\n';
	return 0;
}

