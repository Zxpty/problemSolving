#include <bits/stdc++.h>
#include <queue>

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

void ONO(){
	int n, m, r; read(n, m, r);
	vector<vector<pair<int, int>>> adj(n);
	for(int i = 0; i < m; i++){
		int u, v; read(u, v);
		u--, v--;
		adj[u].push_back({v, 0});
		adj[v].push_back({u, 0});
	}
	for(int i = 0; i < r; i++){
		int u, v, w; read(u, v, w);
		u--, v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	vector<int> vis(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});
	long long sum = 0;
	while(!pq.empty()){
		auto [wt, node] = pq.top(); pq.pop();
		if(vis[node]) continue;
		sum += wt;
		vis[node] = 1;
		for(auto [v, w] : adj[node]){
			if(vis[v]) continue;
			pq.push({w, v});
		}
	}

	ps(sum);

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
