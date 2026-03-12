#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);}
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.first, p.second);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.first, ", ", x.second, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.first, ' ', x.second); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}

const int MX = 1e9;

vector<vector<int>> adj;

struct LCA{
	int n, l, timer;
	vector<vector<int>> up;
	vector<int> in, out, depth;

	LCA(int _n, int root = 1){
		timer = 0, l = ceil(log2(_n));
		n = _n + 1;
		in.resize(n), out.resize(n);
		up.resize(n, vector<int>(l + 1));
		depth.resize(n);
		depth[root] = 0; 
		dfs(root, root);
	}
	
	void dfs(int v, int p){
		depth[v] = depth[p] + 1;
		in[v] = ++timer;
		up[v][0] = p;
		for(int i = 1; i <= l; i++) up[v][i] = up[up[v][i - 1]][i - 1];
		for(int u : adj[v]){
			if(u == p) continue;
			dfs(u, v);
		}
		out[v] = ++timer;
	}

	bool is_ancestor(int u, int v){
		return in[u] <= in[v] && out[u] >= out[v];
	}

	int query(int u, int v){
		if(is_ancestor(u, v)) return u;
		if(is_ancestor(v, u)) return v;
		for(int i = l; ~i; i--){
			if(!is_ancestor(up[u][i], v)) u = up[u][i];
		}
		return up[u][0];
	}

	int ancestor(int x, int k){
		assert(depth[x] >= k);
		for(int i = 0; i <= l; i++){
			if(k & (1 << i)) x = up[x][i];
		}
		return x;
	}

	int distance(int u, int v){
		return depth[u] + depth[v] - 2 * depth[query(u, v)];
	}
};


void ONO(){
	int n; read(n);
	adj.assign(n + 1, {});
	for(int i = 0; i < n - 1; i++){
		int u, v; read(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	LCA lca(n + 1, 1);
	int q; read(q);
	auto check = [&](int x, int a, int b){
		return lca.distance(a, x) + lca.distance(x, b) == lca.distance(a, b);
	};
	for(int Q = 0; Q < q; Q++){
		int k; read(k);
		int L, R; read(L, R);
		bool ok = 0;
		for(int i = 1; i < k; i++){
			int a, b; read(a, b);
			vector<int> cand = {
				lca.query(L, a),
				lca.query(L, b),
				lca.query(R, a),
				lca.query(R, b),
			};
			vector<int> good;
			for(int x : cand){
				if(check(x, L, R) && check(x, a, b)) good.push_back(x);
			}
			if(good.empty()){
				ok = 1;
				break;
			}
			int newL = good[0], newR = good[0];
			for(int x : good){
				for(int y : good){
					if(lca.distance(x, y) > lca.distance(newL, newR)){
						newL = x;
						newR = y;
					}
				}
			}
			L = newL;
			R = newR;
		}
		if(ok) ps(0);
		else ps(lca.distance(L, R) + 1);
	}
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	for(int i = 0; i < t; i++){
		cout << "Case " <<  i + 1 << ":\n";
		ONO();
	}
	return 0;
}
