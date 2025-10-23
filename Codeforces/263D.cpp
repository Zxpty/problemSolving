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
const int MX = 1e5;

void GA(){
	int n, m, k; read(n, m, k);
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++){
		int u, v; read(u, v); u--, v--;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> vis(n);
	vector<int> Parent(n, -1);
	bool found = false;
	function<void(int, int)> dfs = [&](int node, int parent){
		vis[node] = 1;
		Parent[node] = parent;
		for(auto v : adj[node]){
			if(found) return;
			if(!vis[v]){
				dfs(v, node);
			}else if(v != parent){
				vector<int> ans;
				int x = node;
				while(x != v && x != -1){
					ans.push_back(x);
					x = Parent[x];
				}
				ans.push_back(v);
				if(sz(ans) >= k + 1){
					reverse(ans.begin(), ans.end());
					ps(ans.size());
					for(int x : ans){
						cout << x + 1<< " ";
					}
					found = true;
					return;
				}

			}
		}
	};
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i, -1);
		}
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
