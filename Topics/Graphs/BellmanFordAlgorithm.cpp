#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

//helps to detect negative cycles
// only applied in directed graphs

int main() {
	cpu();
	int N, source; cin >> N >> source;
	vector<array<int, 3>> edges;
	for(int i = 0; i < N; i++){
		int u, v, w; cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	vector<int> dis(N, 1e8);
	dis[source] = 0;
	for(int i = 0; i < N - 1; i++){
		for(auto e : edges){
			int u = e[0];
			int v = e[1];
			int w = e[2];
			if(dis[u] != 1e8 and dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
			}
		}
	}
	// here we can do the n-th repet for detect negative cycle
	bool negative_cycle = 0;
	for(auto e : edges){
		int u = e[0];
		int v = e[1];
		int w = e[2];
		if(dis[u] != 1e8 and dis[u] + w < dis[v]){
			negative_cycle = 1;
			break;
		}
	}
	if(negative_cycle){
		cout << "Negative cycle has been found" << '\n';
	}else{
		for(int x : dis){
			cout << x << " ";
		}
	}
	return 0;
}
/*
 5 0
 1 3 2
 4 3 -1
 2 4 1
 1 2 1
 0 1 5
*/

