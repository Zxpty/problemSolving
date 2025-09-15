#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
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



typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;
void solve(){
	int n, m1, m2; read(n, m1, m2);
	vector<vector<int>> adj1(n + 1),adj2(n + 1);
	vector<bool> vis(n + 1, false), vis2(n + 1, false);
	vector<pair<int, int>> edges;
	vector<vector<int>> componente;
	vector<int> id(n + 1);
	for(int i = 0; i < m1; i++){
		int u, v; read(u, v);
		edges.push_back({u, v});
	}
	//dbg(edges);
	for(int i = 0; i < m2; i++){
		int u, v; read(u ,v);
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	//dbg(adj2);

	int cn = 0;
	vector<int> connections;

	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		id[node] = cn;
		connections.push_back(node);
		for(int v : adj2[node]){
			if(vis[v])continue;
			dfs(v);
		}
	};


	function<void(int)> dfs2 = [&](int node){
		vis2[node] = 1;
		for(int v : adj1[node]){
			if(vis2[v])continue;
			dfs2(v);
		}
	};

	for(int i = 1; i <= n; i++){
		if(vis[i])continue;
		connections.clear();
		dfs(i);
		componente.push_back(connections);
		dbg(connections);
		cn++;
	}
	//dbg(componente);
	int ans = 0;
	for(auto [u, v] : edges){
		if(id[u] != id[v]) ans++;
		else{
			adj1[u].push_back(v);
			adj1[v].push_back(u);
		}
	}
	//dbg(ans);
	//dbg(id);
	//dbg(adj1);

	for(int i = 0; i< cn; i++){
		int cnt = 0;
		for(int node : componente[i]){
			if(vis2[node])continue;
			dfs2(node);
			cnt++;
		}
		ans+= cnt - 1;
	}
	ps(ans);
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
