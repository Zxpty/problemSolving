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

	
	int cn = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cn++;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int node = q.front(); q.pop();
				for(int v : adj[node]){
					if(!vis[v]){
						vis[v] = 1;
						q.push(v);
					}
				}
			}
		}
	}
	cout << m - n + cn;
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
