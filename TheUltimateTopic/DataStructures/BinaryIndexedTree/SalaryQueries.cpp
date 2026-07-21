#include <algorithm>
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

template <typename T>
struct FenwickTree{
	vector<T> bit;
	int n;
	FenwickTree(int n) : bit(n, 0), n(n) {}

	FenwickTree(const vector<T>& a) : bit(int(a.size()), 0), n(a.size()){
		for(int i = 0; i < n; i++){
			update(i, a[i]);
		}
	}

	void update(int idx, T delta){
		for(; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}

	T query(int r){ // summation in range of 0 to i
		T ret = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	T query(int l, int r){
		return query(r) - query(l - 1);
	}
};



void GA(){
	int n, m; read(n, m);
	vector<long long> r(n); read(r);
	vector<array<int, 3>> queries;
	vector<int> s;
	
	for(int i = 0; i < n; i++){
		s.push_back(r[i]);
	}
	for(int i = 0; i < m; i++){
		char type; read(type);
		int a, b; read(a, b);
		queries.push_back({type == '?', a, b});
		if(type == '!') s.push_back(b);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	auto get = [&](long long x){
		return lower_bound(s.begin(), s.end(), x) - s.begin();
	};

	int ln = int(s.size());
	FenwickTree<long long> FT(ln);
	for(int i = 0; i < n; i++){
		FT.update(get(r[i]), 1);
	}

	for(auto [type, a, b] : queries){
		if(type == 0){
			int pos = a - 1;
			FT.update(get(r[pos]), -1);
			FT.update(get(b), 1);
			r[pos] = b;
		}else if(type == 1){
			int right = upper_bound(s.begin(), s.end(), b) - s.begin();
			int left = upper_bound(s.begin(), s.end(), a - 1) - s.begin();
			//dbg(left, right);
			cout << FT.query(right - 1) - FT.query(left - 1) << '\n';
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
