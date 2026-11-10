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
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x; cin >> x;
			if(x == 1) adj[i].push_back(j);
		}
	}
	auto bfs = [&](int node){
		//cout << "Bfs for node: " << node << "\n";
		vector<int> dist(n, -1);
		queue<int> q;
		dist[node] = 0;
		q.push(node);
		while(!q.empty()){
			int curr = q.front(); q.pop();
			for(int v : adj[curr]){
				if(dist[v] == -1){
					dist[v] = dist[curr] + 1;
					q.push(v);
				}else if(dist[v] == 0){
					return dist[curr] + 1;
				}
			}
		}
		return 0;
	};

	for(int i = 0; i < n; i++){
		int get = bfs(i);
		if(get == 0){
			cout << "NO WAY\n";
		}else{
			cout << get << "\n";
		}
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
