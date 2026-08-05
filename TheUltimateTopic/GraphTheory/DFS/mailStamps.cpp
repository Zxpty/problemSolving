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
	map<int, vector<int>> adj;
	for(int i = 0; i < n; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int node = -1;
	for(auto [u, grade] : adj){
		if(grade.size() == 1){
			node = u;
			break;
		}
	}
	vector<int> ans;
	function<void(int, int)> dfs = [&](int node, int parent){
		ans.push_back(node);
		for(auto v : adj[node]){
			if(v == parent) continue;
			dfs(v, node);
		}
	};
	dfs(node, -1);
	for(int x : ans) cout << x << " ";

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
