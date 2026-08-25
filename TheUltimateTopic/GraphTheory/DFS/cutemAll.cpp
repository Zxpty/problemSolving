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
	int aristas = n - 1;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < aristas; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if(n % 2 == 1){
		cout << -1;
		return;
	}

	vector<int> size(n + 1);
	function<void(int, int)> dfs = [&](int node, int parent){
		size[node] = 1;
		for(int v : adj[node]){
			if(v != parent){
				dfs(v, node);
				size[node] += size[v];
			}
		}
	};
	dfs(1, -1);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		//cout << "size" << i << " " << size[i] << endl; 
		if(size[i] % 2 == 0) ans++;
	}
	cout << ans - 1;
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
