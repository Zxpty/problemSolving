#include <bits/stdc++.h>
#include <iterator>
#include <queue>
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
const ll MX = 1e9+7;

void solve(){
	int n, m; read(n, m);
	vector<vector<int>> adj(n + 1), adj2(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; read(u, v);
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}
	vector<int> vis(n + 1, false), vis2(n + 1, false);

	function<void(int, int)> bfs = [&](int start, int type){
		queue<int> q;
		q.push(start);
		(type == 1 ? vis[start] = 1  : vis2[start] = 1 );
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int v : (type == 1 ? adj[u] : adj2[u])){
				if((type == 1 ? !vis[v] : !vis2[v])){
					(type == 1 ? vis[v] = 1 : vis2[v] = 1);
					q.push(v);
				}
			}
		}
	};
	bfs(1, 1);
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			ps("NO");
			cout<<1 << ' '<<i;
			ps();
			return;
		}
	}

	bfs(1, 2);
	for(int i = 1; i <= n; i++){
		if(!vis2[i]){
			ps("NO");
			cout<<i << ' '<<1;
			ps();
			return;
		}
	}

	ps("YES");

		
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
