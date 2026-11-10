#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;
int main(){
	cpu();
	int n;
	int tc = 1;
	while(cin >> n && n != 0){
		map<int, vector<int>> adj;
		for(int i = 0; i < n; i++){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int start, ttl;
		while(cin >> start >> ttl){
			if(start == 0 && ttl == 0){
				break;
			}
			map<int, int> visited;
			queue<pair<int, int>> q;
			q.push({start, 0});
			visited[start] = 1;
			int cn = 1;
			while(!q.empty()){
				auto [u, dist] = q.front(); q.pop();
				if(dist == ttl) continue;
				for(int v : adj[u]){
					if(!visited[v]){
						visited[v] = 1;
						cn++;
						q.push({v, dist + 1});
					}
				}
			}
			cout << "Case " << tc << ": " << int(adj.size()) - cn << " nodes not reachable from node " << start << " with TTL = " << ttl << ".\n"; 
			tc++;
		}

	}
	return 0;
}
