#include <bits/stdc++.h>

#ifdef local
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int mx = 1e9+7;

void uwu(){
	int n; cin >> n;
	vector<int> x(n + 1);
	vector<int> y(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}

	vector<int> vis(n + 1);
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(x[i] == x[j] || y[i] == y[j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int components = 0;
	auto bfs = [&](int node){
		queue<int> q;
		q.push(node);
		while(!q.empty()){
			int node = q.front(); q.pop();
			for(auto v : adj[node]){
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	};
	for(int i = 1; i <=n ;i++){
		if(!vis[i]){
			components++;
			bfs(i);
		}
	}
	cout << components;
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		uwu();
	}
	return 0;
}
