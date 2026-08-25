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
	map<int, int> mp;
	vector<set<int>> adj(n + 1);
	for(int u = 1; u <= n; u++){
		int v; cin >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}


	int close = 0;
	int open = 0;
	int mx = 0;
	vector<int> vis(n + 1);
	bool ok = 0;
	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		if(adj[node].size() == 1) ok = 1;
		for(int v : adj[node]){
			if(!vis[v]) dfs(v);
		}
	};
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
			if(ok) open++;
			else close++;
			ok = 0;
			mx++;
		}
	}

	int mn = close + min(1, open);
	cout << mn << " " << mx << '\n';

}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
