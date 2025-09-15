#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

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
const long long inf = 1e18;
void GA(){
	int n, m; read(n, m);
	vector<vector<pair<int, long long>>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; read(u, v);
		long long w; read(w);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	vector<long long> dis(n + 1, inf);
	
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	dis[1] = 0;
	pq.push({0LL, 1});
	vector<long long> p(n + 1);
	p[1] = -1;
	while(!pq.empty()){
		auto [distance, node] = pq.top(); pq.pop();
		if(dis[node] != distance) continue;
		for(auto [v, w] : adj[node]){
			long long new_dist = distance + w;
			if(new_dist < dis[v]){
				dis[v] = new_dist;
				pq.push({new_dist, v});
				p[v] = node;
			}
		}
	}
	if(dis[n] == inf){
		ps(-1);
		return;
	}

	int start = n;
	vector<int> ans;
	while(p[start] != -1){
		ans.push_back(start);
		start = p[start];
	}

	reverse(ans.begin(), ans.end());
	cout << 1 << " ";
	for(int x : ans) cout << x << ' ';
	ps();
	
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
