#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int INF = 1e9+7;

void UWU(){
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> dis(n + 1, INF), dis2(n + 1, INF);

	queue<pair<int, int>> q;
	dis[1] = 0;
	q.push({1, 0});

	while(!q.empty()){
		auto [curr, d] = q.front(); q.pop();
		int nd = d + 1;
		for(int v : adj[curr]){
			if(nd < dis[v]){
				dis2[v] = dis[v];
				dis[v] = nd;
				q.push({v, dis[v]});
			}else if(nd > dis[v] && nd < dis2[v]){
				dis2[v] = nd;
				q.push({v, dis2[v]});
			}
		}
	}

	if(dis2[n] == dis[n] + 1){
		cout << "possible" << endl;
	}else{
		cout << "impossible" << endl;
	}

}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
