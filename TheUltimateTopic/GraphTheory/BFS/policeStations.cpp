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
	int n, k, d; cin >> n >> k >> d;
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<int> dist(n + 1, -1);
	vector<int> good(n + 1);
	queue<int> q;
	for(int i = 0; i < k; i++){
		int police_station; cin >> police_station;
		dist[police_station] = 0;
		q.push(police_station);
	}

	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back({v, (i + 1)});
		adj[v].push_back({u, (i + 1)});
	}


	while(!q.empty()){
		int node = q.front(); q.pop();
		for(auto [v, id] : adj[node]){
			if(dist[v] == -1){
				dist[v] = dist[node] + 1;
				q.push(v);
				good[id] = 1;
			}
		}
	}

	vector<int> ans;
	for(int i = 1; i < n; i++){
		//cout << "good: " << i << " " <<  good[i] << " " << endl;
		if(!good[i]) ans.push_back(i);
	}
	cout << int(ans.size()) << '\n';
	for(int x : ans){
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
