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

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
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

struct SCC{
	int N = 0, id;
	vector<vector<int>> adj;
	vector<int> ind, low;
	stack<int> s;
	vector<bool> in_stack;
	vector<vector<int>> components;
	vector<int> component_id;
 
	//1-indexed
	SCC(int n = 0){ N = n + 1, adj.assign(N, {}); }
	SCC(const vector<vector<int>> & _adj){ adj = _adj, N = adj.size(); }
 
	void add_edge(int from, int to){
		adj[from].push_back(to);
	}
 
	void dfs(int u){
		low[u] = ind[u] = id++;
		s.push(u);
		in_stack[u] = true;
		for(int v : adj[u]){
			if(ind[v] == -1){
				dfs(v);
				low[u] = min(low[u], low[v]);
			}else if(in_stack[v]){
				low[u] = min(low[u], ind[v]);
			}
		}
		if(low[u] == ind[u]){
			components.emplace_back();
			vector<int> & comp = components.back();
			while(true){
				assert(!s.empty());
				int x = s.top(); s.pop();
				in_stack[x] = false;
				component_id[x] = components.size() - 1;
				comp.push_back(x);
				if(x == u) break;
			}
		}
	}
 
	vector<vector<int>> get(){
		ind.assign(N, - 1); low.assign(N, -1); component_id.assign(N, -1);
		s = stack<int>();
		in_stack.assign(N, false);
		id = 0;
		components = {};
		for(int i = 1; i < N; i++)
			if(ind[i] == -1) dfs(i);
 
		// reverse(components.begin(), components.end()); return components; // SCC in topological order
		return components; // SCC in reverse topological order
	}
};



void ONO(){
	int n, m; read(n, m);
	SCC scc(n);
	for(int i = 0; i < m; i++){
		int u, v; read(u, v);
		scc.add_edge(u, v);
	}
	vector<vector<int>> components = scc.get();
	dbg(components);
	int q; read(q);
	while(q--){
		int type, node; read(type, node);
		if(type == 1){

		}else{

		}
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
