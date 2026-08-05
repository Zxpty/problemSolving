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
	vector<int> r(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> r[i];
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; i++){
		adj[i].push_back(r[i]);
		adj[r[i]].push_back(i);
	}

	int cn = 0;
	vector<int> vis(n + 1);
	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		for(auto v : adj[node]){
			if(!vis[v]){
				dfs(v);
			}
		}
	};
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cn++;
			dfs(i);
		}
	}
	cout << cn << '\n';
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
