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

	vector<int> dis(n + 1, -1);
	vector<int> padre(n + 1);
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	padre[1] = -1;

	while(!q.empty()){
		int curr = q.front(); q.pop();
		if(curr == n){
			vector<int> ans;
			ans.push_back(curr);
			while(curr != 1){
				curr = padre[curr];
				ans.push_back(curr);
			}
			reverse(ans.begin(), ans.end());
			cout << int(ans.size()) << '\n';
			for(int x : ans){
				cout << x << " "; 
			}
			return;
		}
		for(int v : adj[curr]){
			if(dis[v] == -1){
				dis[v] = dis[curr] + 1;
				padre[v] = curr;
				q.push(v);
			}
		}

	}
	cout << "IMPOSSIBLE";
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
