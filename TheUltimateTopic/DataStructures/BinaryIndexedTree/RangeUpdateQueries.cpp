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
	int n, q; read(n, q);
	vector<long long> r(n); read(r);

	FenwickTree<long long> FT(n);
	FT.update(0, r[0]);
	for(int i = 1; i < n; i++){
		FT.update(i, r[i] - r[i - 1]);
	}
	for(int i = 0; i < q; i++){
		int type; read(type);
		if(type == 1){
			int left, right; read(left, right);
			long long amount; read(amount);
			left--, right--;
			FT.update(left, amount);
			if(right + 1 < n) FT.update(right + 1,  -amount);

		}else{
			int k; read(k);
			k--;
			cout << FT.query(k) << '\n';
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
