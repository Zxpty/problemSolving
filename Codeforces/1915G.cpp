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

const long long INF = 1e18;

void ONO(){
	int n, m; read(n, m);
	vector<vector<pair<int, int>>> adj(n);
	for(int i = 0; i < m; i++){
		long long u, v, w; read(u, v, w);
		u--, v--;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	vector<long long> s(n); read(s);

	int MAXS = *max_element(s.begin(), s.end());
	vector<vector<long long>> dis(n, vector<long long>(MAXS + 1, INF));
	priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<>> pq;
	dis[0][s[0]] = 0;
	pq.push({0, 0, s[0]});
	while(!pq.empty()){
		auto [d, u, slow] = pq.top(); pq.pop();

		if(d != dis[u][slow]) continue;

		for(auto [v, w] : adj[u]){
			long long new_slow = min(s[v], slow);
			long long new_time = d + w * slow;
			if(dis[v][new_slow] > new_time){
				dis[v][new_slow] = new_time;
				pq.push({new_time, v, new_slow});
			}
		}
	}

	long long ans = INF;
	for(auto i = 0; i <= MAXS; i++){
		ans = min(ans, dis[n - 1][i]);
	}
	ps(ans);
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
