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
	DSU dsu(n);
	int ans = 0;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		if(dsu.find(u) != dsu.find(v)){
			dsu.merge(u, v);
			ans++;
		}
	}
	cout << ans << '\n';
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
