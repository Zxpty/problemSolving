#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define sz(a) ((int)(a).size())
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.ff, ", ", x.ss, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.ff, ' ', x.ss); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}


typedef int64_t i64;
const long long MX = 1e9+7;

struct LCA{
	int n, l, timer = 0;
	vector<vector<int>> up, adj;
	vector<int> depth, in, out;
 
	LCA(int _n) {
		n = _n + 1;
		l = ceil(log2(n));
		up.resize(n, vector<int>(l + 1));
		adj.resize(n);
		depth.resize(n);
		in.resize(n);
		out.resize(n);
	}
 
	void add_edge(int p, int u){
		adj[p].push_back(u);
		adj[u].push_back(p);
	}
 
	void dfs(int u = 1, int p = 1){
		up[u][0] = p;
		depth[u] = depth[p] + 1;
		in[u] = ++timer;
		for(int level = 1; level <= l; level++){
			up[u][level] = up[up[u][level - 1]][level - 1];
		}
		for(int v : adj[u]){
			if(v == p) continue;
			dfs(v, u);
		}
		out[u] = ++timer;
	}
 
	bool is_ancestor(int p, int u){
		return in[p] <= in[u] && out[p] >= out[u];
	}

	int query(int u, int v){
		if(is_ancestor(u, v)) return u;
		if(is_ancestor(v, u)) return v;

		for(int bit = l; bit >= 0; bit--){
			if(is_ancestor(up[u][bit], v)) continue;
			u = up[u][bit];
		}
		return up[u][0];
	}

	int ancestor(int u, int k){
		if(depth[u] <= k) return -1;
		for(int bit = 0; bit <= l; bit++){
			if(k >> bit & 1) u = up[u][bit];
		}
		return u;
	}

	int distance(int u, int v){
		return depth[u] + depth[v] - 2 * depth[query(u, v)];
	}
};

void GA(){
	int n; read(n);
	LCA lca(n);
	vector<pair<int, int>> edges;
	for(int i = 0; i < n - 1; i++){
		int u, v; read(u, v);
		edges.push_back({u, v});
		lca.add_edge(u, v);
	}
	lca.dfs();
	vector<int> difference_array(n + 1);
	int q; read(q);
	while(q--){
		int left, right; read(left, right);
		difference_array[left]+=1;
		difference_array[right]+=1;
		int w = lca.query(left, right);
		difference_array[w]-=2;
	}

	vector<int> dp(n + 1);
	for(int i = 1; i <= n;i++){
		dp[i] = difference_array[i];
	}
	function<void(int, int)> dfs = [&](int node, int parent){
		for(int v : lca.adj[node]){
			if(v == parent) continue;
			dfs(v, node);
			dp[node] += dp[v];
		}
	};

	dfs(1, -1);
	for(auto [u, v] : edges){
		if(lca.depth[u] > lca.depth[v]) swap(u, v);
		cout << dp[v] << " ";
	}


}

int main(){
	cpu(); int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
