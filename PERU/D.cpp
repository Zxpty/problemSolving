#include <algorithm>
#include <bits/stdc++.h>

#ifdef local
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int mx = 1e9+7;

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

void uwu(){
	int n, m, q; cin >> n >> m >> q;
	vector<int> x(n), y(n);
	map<int, vector<int>> id;
	for(int i = 0; i < n; i++){
		cin >> x[i];
		id[x[i]].push_back(i + 1);
	}
	for(int i = 0; i < n; i++){
		cin >> y[i];
	}
	vector<int> xs = x;
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DSU dsu_right(n), dsu_left(n);
	vector<int> vis_right(n + 1), vis_left(n + 1);
	int comp_right = 0, comp_left = 0;
	vector<int> pre, suf;
	for(auto [x, vs] : id){
		for(int u : vs){
			vis_right[u] = 1;
			comp_right++;
		}

		for(int u : vs){
			for(int v : adj[u]){
				if(vis_right[v]){
					if(dsu_right.merge(u, v)){
						comp_right--;
					}
				}
			}
		}
		pre.push_back(comp_right);
	}

	vector<pair<int, vector<int>>> go(id.begin(), id.end());
	reverse(go.begin(), go.end());

	for(auto [x, vs] : go){
		for(int u : vs){
			vis_left[u] = 1;
			comp_left++;
		}
		for(int u : vs){
			for(int v : adj[u]){
				if(vis_left[v]){
					if(dsu_left.merge(u, v)){
						comp_left--;
					}
				}
			}
		}
		suf.push_back(comp_left);
	}
	reverse(suf.begin(), suf.end());
	while(q--){
		int point; cin >> point;
		int id_left = lower_bound(xs.begin(), xs.end(), point) - xs.begin() - 1;
		int id_right = upper_bound(xs.begin(), xs.end(), point) -xs.begin();
		int ans = 0;
		if(id_left >= 0){
			ans += pre[id_left];
		}
		if(id_right < int(xs.size())){
			ans += suf[id_right];
		}
		cout << ans << ' ';
	}
	cout << '\n';
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		uwu();
	}
	return 0;
}
