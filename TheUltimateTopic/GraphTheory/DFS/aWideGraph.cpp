#include <algorithm>
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

void UWU(){
	int n; cin >> n;
	int m = n - 1;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> distA(n + 1), distB(n + 1), distC(n + 1);
	function<void(int, int, vector<int>&)> dfs = [&](int node, int parent, vector<int>& dist){
		for(auto v : adj[node]){
			if(v != parent){
				dist[v] = dist[node] + 1;
				dfs(v, node, dist);
			}
		}
	};
	distA[1] = 0;
	dfs(1, 0, distA);

	int mx = 0, node = 1;
	for(int i = 1; i <= n; i++){
		if(distA[i] > mx){
			mx = distA[i];
			node = i;
		}
	}

	dfs(node, 0, distB);
	mx = 0, node = 1;
	for(int i = 1; i <= n; i++){
		if(distB[i] > mx){
			mx = distB[i];
			node = i;
		}
	}
	dfs(node, 0, distC);

	vector<int> dist(n + 1);
	for(int i = 1; i <= n; i++){
		dist[i] = max(distB[i], distC[i]);
	}

	sort(dist.begin(), dist.end());
	int left = 0;
	for(int i = 1; i <= n; i++){
		while(left < n && dist[left] < i) left++;
		cout << min(n, left) << " ";
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
