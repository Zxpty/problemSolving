#include <bits/stdc++.h>
#include <queue>

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
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> order(n + 1);
	vector<int> pos(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> order[i];
	}
	for(int i = 1; i <= n; i++){
		pos[order[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		sort(adj[i].begin(), adj[i].end(), [&](auto a, auto b){
				return pos[a] < pos[b];
				});
	}

	if(order[1] != 1){
		cout << "No";
		return;
	}
	vector<int> vis(n + 1);
	vector<int> me;

	queue<int> q;
	q.push(1);
	vis[1] = 1;
	int start = 2;
	while(!q.empty()){
		int node = q.front(); q.pop();
		me.push_back(node);
		for(int v : adj[node]){
			if(!vis[v]){
				vis[v] = 1;
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(me[i - 1] != order[i]){
			cout << "No";
			return;
		}
	}
	cout << "Yes";


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
