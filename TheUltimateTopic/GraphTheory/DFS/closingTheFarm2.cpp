#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

struct DSU{
	vector<int> parent, size;
	DSU(int n){
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for(int i = 1; i <= n; i++) parent[i] = i;
	}

	int find(int node){
		if(node == parent[node]) return node;
		return parent[node] = find(parent[node]);
	}

	bool merge(int u, int v){
		int up = find(u);
		int vp = find(v);
		if(up == vp) return false;
		if(size[up] < size[vp]) swap(up, vp);
		parent[vp] = up;
		size[up] += size[vp];
		return true;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	DSU dsu(n);
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> orden_cierres(n);
	for(int i = 0; i < n; i++){
		cin >> orden_cierres[i];
	}

	reverse(orden_cierres.begin(), orden_cierres.end());

	vector<int> open(n + 1, 0);
	vector<int> ans(n);
	int componentes_actuales = 0;

	for(int i = 0; i < n; i++){
		int node = orden_cierres[i];
		open[node] = 1;
		componentes_actuales++;
		for(int v : adj[node]){
			if(open[v]){
				if(dsu.merge(node, v)) componentes_actuales--;
			}
		}
		ans[i] = (componentes_actuales == 1 ? 1 : 0);
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < n; i++){
		if(ans[i]) cout << "YES\n";
		else cout << "NO\n";
	}
}
int main(){
	cpu();
	int t = 1;
	//read(t);
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	while(t--){
		solve();
	}
	return 0;
}

