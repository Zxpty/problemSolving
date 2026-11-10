#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

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

void UWU(){
	int n, m; cin >> n >> m;
	vector<pair<int,int>> red, blue;
	DSU dsu_red(n + 1), dsu_blue(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, color; cin >> u >> v >> color;
		if(color == 0){
			red.push_back({u, v});
		}else{
			blue.push_back({u, v});
		}
	}

	for(auto [u, v] : red){
		dsu_red.merge(u, v);
	}

	for(auto [u, v] : blue){
		if(dsu_red.find(u) == dsu_red.find(v)){
			cout << "NO\n";
			return;
		}
	}

	for(auto [u, v] : blue){
		dsu_blue.merge(u, v);
	}

	for(auto [u, v] : red){
		if(dsu_blue.find(u) == dsu_blue.find(v)){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";

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
