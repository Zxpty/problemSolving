#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
	cpu();
	int n, m; cin >> n >> m;
	vector<int> vis(n);
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
	}
	stack<int> st;
	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		for(auto v : adj[node]){
			if(!vis[v]) dfs(v);
		}
		st.push(node);
	};
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	vector<int> ans;
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	for(int x : ans){
		cout << x << " ";
	}
	return 0;
}
/*
4 3
3 0
1 0
2 0
*/

