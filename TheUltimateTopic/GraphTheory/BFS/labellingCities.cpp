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

	for(int i = 1; i <= n; i++){
		adj[i].push_back(i);
	}

	map<vector<int>, int> mp;
	int id = 1;
	for(int i = 1; i <= n; i++){
		sort(adj[i].begin(), adj[i].end());
		if(!mp.count(adj[i])){
			mp[adj[i]] = id++;
		}
	}

	vector<int> vagon(n + 1);
	for(int i = 1; i <= n; i++){
		vagon[i] = mp[adj[i]];
	}

	vector<set<int>> adj2(n + 1);

	for(int i = 1; i <= n; i++){
		for(int v : adj[i]){
			if(vagon[i] != vagon[v]){
				adj2[vagon[i]].insert(vagon[v]);
			}
		}
	}

	int inicio = 0;
	for(int i = 1; i <= id - 1; i++){
		if(adj2[i].size() > 2){
			cout << "NO\n";
			return;
		}
		if(adj2[i].size() <= 1){
			inicio = i;
		}
	}

	vector<int> val(id, 0);
	int curr = inicio;
	int padre = 0;
	int start = 1;

	while(curr != 0){
		val[curr] = start++;
		int sgt = 0;
		for(int v : adj2[curr]){
			if(v != padre){
				sgt = v;
			}
		}
		padre = curr;
		curr = sgt;
	}

	cout << "YES\n";
	for(int i = 1; i <= n; i++){
		cout << val[vagon[i]] << " ";
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
