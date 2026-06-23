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

void GA(){
	int n, m; read(n, m);
	vector<vector<pair<int, int>>> p(n + 1);
	for(int i = 0; i < m; i++){
		int pre, year; read(pre, year);
		int citie = i + 1;
		p[pre].push_back({year, citie});
	}
	for(int i = 1; i <= n; i++){
		sort(p[i].begin(), p[i].end());
	}

	map<int, string> mp;
	for(int i = 1; i <= n; i++){
		vector<pair<int, int>>& r = p[i];
		int sz = int(r.size());
		string prefecture = to_string(i);
		string first = prefecture;
		int need_first = 6 - int(prefecture.size());
		first = string(need_first, '0') + first;
		for(int j = 0; j < sz; j++){
			auto [_, citie] = r[j];
			string temp = first;
			string id_number = to_string(j + 1);
			int need_second = 6 - int(id_number.size());
			id_number = string(need_second, '0') + id_number;
			temp += id_number;
			mp[citie] = temp;
		}
	}

	for(int i = 1; i <= m; i++){
		ps(mp[i]);
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
