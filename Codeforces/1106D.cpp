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
	set<int> st;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n + 1);
	st.insert(1);

	while(!st.empty()){
		if(vis[*st.begin()]){
			st.erase(st.begin());
			continue;
		}
		int node = *st.begin();
		vis[node] = 1;
		st.erase(st.begin());
		cout << node << " ";
		for(auto v : adj[node]){
			if(!vis[v]){
				st.insert(v);
			}
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
