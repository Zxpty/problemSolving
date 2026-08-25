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
	vector<int> cat(n + 1);
	for(int i = 1; i <= n; i++) cin >> cat[i];
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<pair<int, int>> q;
	vector<bool> vis(n + 1, false);
	q.push({1, cat[1]});
	vis[1] = 1;
	int ans = 0;
	while(!q.empty()){
		auto [val, dis] = q.front(); q.pop();
		if(dis > m){
			continue;
		}
		bool is_leaft = 1;
		for(auto v : adj[val]){
			if(!vis[v]){
				vis[v] = 1;
				is_leaft = 0;
				if(cat[v] == 1){
					q.push({v, dis + 1});
				}else{
					q.push({v, 0});
				}
			}
		}
		if(is_leaft) ans++;
	}

	cout << ans;
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
