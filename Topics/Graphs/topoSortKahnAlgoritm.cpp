#include <bits/stdc++.h>
#include <queue>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;


/*
 * Topological sort only is in DAG
 * Kahns Algorithm
 * we need a queue 
 * indegree = number of incoming edges to a node
 * 5 -> 2
 * 5 -> 0
 * 4 -> 0
 * 4 -> 1
 * 3 -> 1
 * 2 -> 3
 *        	0 1 2 3 4 5
 * indegree 2 2 1 1 0 0
 *
 * setps:
 * 1) insert all node wit indegree 0
*/
int main() {
	cpu();
	int N, M; cin >> N >> M;
	vector<int> indegree(N);
	vector<vector<int>> adj(N);
	for(int i = 0; i < M; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	for(int i = 0; i < N; i++){
		for(auto v : adj[i]){
			indegree[v]++;
		}
	}
	queue<int> q;
	for(int i = 0; i < N; i++){
		if(indegree[i] == 0) q.push(i);
	}


	vector<int> Topological;
	while(!q.empty()){
		int node = q.front(); q.pop();
		Topological.push_back(node);
		for(auto v : adj[node]){
			indegree[v]--;
			if(indegree[v] == 0) q.push(v);
		}
	}
	for(int x : Topological) cout << x << " ";
	return 0;
}

