#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

int main() {
    cpu();
    int N, M; 
    cin >> N >> M;
    
    vector<vector<int>> adj(N);
    vector<int> vis(N);

    for (int i = 0; i < M; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
	}

    bool hasCycle = false;

    function<void(int, int)> dfs = [&](int node, int parent) {
        vis[node] = 1;
        for (int v : adj[node]) {
            if (!vis[v]) dfs(v, node);
            else if (v != parent) hasCycle = true;
        }
    };

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            dfs(i, -1);
            if (hasCycle) break;
        }
    }

    if (hasCycle) cout << "There is a cycle in the graph\n";
    else cout << "There isn't a cycle in the graph\n";

    return 0;
}
/*
4 4
0 1
0 2 
1 2
2 3
*/
