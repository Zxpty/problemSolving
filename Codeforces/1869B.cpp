#include <bits/stdc++.h>
#include <cstdlib>

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
	int n, k, a, b; read(n, k, a, b);
	a--, b--;
	vector<pair<long long, long long>> coord(n); read(coord);
	vector<pair<long long, long long>> major(k);
	for(int i = 0; i < k; i++){
		major[i] = coord[i];
	}
	long long ans = abs(coord[a].first - coord[b].first) + abs(coord[a].second - coord[b].second);

	long long citya_to_major = 1e18;
	long long cityb_to_major = 1e18;

	for(auto [x, y] : major){
		citya_to_major = min(abs(coord[a].first - x) + abs(coord[a].second - y), citya_to_major);
		cityb_to_major = min(abs(coord[b].first - x) + abs(coord[b].second - y), cityb_to_major);
	}
	ans = min(ans, citya_to_major + cityb_to_major);
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
