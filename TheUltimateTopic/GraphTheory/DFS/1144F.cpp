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
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<pair<int,int>> vertex(m);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		vertex[i] = {u, v};
	}


	vector<int> color(n +  1, -1);
	function<bool(int, int)> dfs = [&](int node, int c){
		color[node] = c;
		for(int v : adj[node]){
			if(color[v] == -1){
				if(!dfs(v, 1 - c)) return false;
			}else if(color[v] == c) return false;
		}
		return true;
	};

	for(int node = 1; node <= n; node++){
		if(color[node] == -1){
			if(!dfs(node, 0)){
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
	for(int i = 0; i < m; i++){
		if(color[vertex[i].first] == 0){
			cout << "1";
		}else{
			cout << "0";
		}
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
