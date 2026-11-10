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
	for(int u = 1; u <= n; u++){
		if(u - r[u] >= 1){
			int v = u - r[u];
			adj[v].push_back(u);
		}
		if(u + r[u] <= n){
			int v = u + r[u];
			adj[v].push_back(u);
		}
	}

	queue<int> q;
	vector<int> dist(n + 1, -1), dist2(n + 1, -1);
	for(int i = 1; i <= n; i++){
		if(r[i] % 2 == 0){
			q.push(i);
			dist[i] = 0;
		}
	}

	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int v : adj[node]){
			if(dist[v] == -1){
				dist[v] = dist[node] + 1;
				q.push(v);
			}
		}
	}

	while(!q.empty()){
		q.pop();
	}

	for(int i = 1; i <= n; i++){
		if(r[i] & 1){
			q.push(i);
			dist2[i] = 0;
		}
	}

	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int v : adj[node]){
			if(dist2[v] == -1){
				dist2[v] = dist2[node] + 1;
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		int mx = max(dist[i], dist2[i]);
		if(mx == 0) cout << -1 << " ";
		else cout << mx << " ";
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
