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
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n + 1);
	vector<int> close(n + 1, 0);
	int cn = n;
	int start = 0;
	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		start++;
		for(int v : adj[node]){
			if(!vis[v] && !close[v]){
				dfs(v);
			}
		}
	};

	vector<int> valid(n);
	iota(valid.begin(), valid.end(), 1);
	set<int> st(valid.begin(), valid.end());
	for(int i = 0; i < n; i++){
		int node; cin >> node;
		int check = *st.begin();
		dfs(check);
		if(start == cn){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
		fill(vis.begin(), vis.end(), 0);
		close[node] = 1;
		cn--;
		st.erase(node);
		start = 0;
	}
}

int main(){
	cpu();
	int t = 1;
	//read(t);
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	while(t--){
		UWU();
	}
	return 0;
}

