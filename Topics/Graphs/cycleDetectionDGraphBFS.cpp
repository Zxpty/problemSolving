#include <bits/stdc++.h>
#include <queue>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
	cpu();
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	vector<int> indegree(N);
	for(int i = 0; i < M; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	queue<int> q;
	for(int i = 0; i < N; i++){
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty()){
		int node = q.front(); q.pop();
		for(int v : adj[node]){
			indegree[v]--;
			if(indegree[v] == 0) q.push(v);
		}
	}
	for(int x : indegree){
		if(x > 0){
			cout << "The graph has a cycle" << '\n';
			return 0;
		}
	}

	cout << "This Graph is a DAG" << '\n';
	return 0;
}
/*

3 3
0 1
1 2
2 0

*/
