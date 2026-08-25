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
	vector<int> color(n + 1, -1);

	auto bfs = [&](int node){
		color[node] = 1;
		queue<int> q;
		q.push(node);
		while(!q.empty()){
			int curr = q.front(); q.pop();
			for(int v : adj[curr]){
				if(color[v] == color[curr]){
					return false;
				}
				if(color[v] == -1){
					color[v] = (color[curr] == 1 ? 2 : 1);
					q.push(v);
				}
			}
		}
		return true;
	};
	for(int i = 1; i <= n; i++){
		if(color[i] == -1){
			if(!bfs(i)){
				cout << -1;
				return;
			}
		}
	}

	vector<int> one, two;
	for(int i = 1; i <= n; i++){
		if(adj[i].size() == 0) continue;
		if(color[i] == 1) one.push_back(i);
		else two.push_back(i);
	}
	cout << int(two.size()) << '\n';
	for(int x : two){
		cout << x << " ";
	}
	cout << '\n';
	cout << int(one.size()) << '\n';
	for(int x : one){
		cout << x << " ";
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
