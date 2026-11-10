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
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>> adj(n + 1);
	vector<int> product(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> product[i];
	}
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> dist(n + 1, -1);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int curr = q.front(); q.pop();
		for(int v : adj[curr]){
			if(dist[v] == -1){
				dist[v] = dist[curr] + 1;
				q.push(v);
			}
		}
	}

	vector<int> ans(k + 1);
	for(int i = 1; i <= n; i++){
		ans[product[i]] = max(ans[product[i]], dist[i]);
	}
	for(int i = 1; i <= k; i++){
		cout << ans[i] << " ";
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
