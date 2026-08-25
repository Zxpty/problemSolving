#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1005;

void UWU(){
	int n; cin >> n;
	vector<int> x(n + 1), y(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}

	vector<int> vis(n + 1);
	vector<pair<int, int>> delta = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};
	vector<vector<int>> adj(n + 1);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			for(auto [rx, ry] : delta){
				int nx = x[i] + rx;
				int ny = y[i] + ry;
				if(nx == x[j] && ny == y[j]){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
	}


	int ans = 0;
	auto bfs = [&](int node){
		vis[node] = 1;
		queue<int> q;
		q.push(node);
		while(!q.empty()){
			int curr = q.front(); q.pop();
			for(int v : adj[curr]){
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	};

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			ans++;
			bfs(i);
		}
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
