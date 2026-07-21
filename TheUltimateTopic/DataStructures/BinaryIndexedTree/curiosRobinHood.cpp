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

struct FenwickTree{
	vector<int> bit;
	int n;
	FenwickTree(int n){
		this -> n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<int> const &a) : FenwickTree(int(a.size())){
		for(size_t i = 0; i < int(a.size()); i++){
			add(i, a[i]);
		}
	}

	int sum(int r){
		int ret = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}
	int sum(int l, int r){
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta){
		for(; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};


void GA(){
	int n, q; cin >> n >> q;
	vector<int> a(n); read(a);
	FenwickTree FT(a);
	for(int i = 0; i < q; i++){
		int type; read(type);
		if(type == 1){
			int pos; read(pos);
			int acc = FT.sum(pos, pos);
			cout << acc << '\n';
			FT.add(pos, -acc);
		}else if(type == 2){
			int pos, money; read(pos, money);
			FT.add(pos, money);
		}else if(type == 3){
			int left, right; read(left, right);
			cout << FT.sum(left, right) << '\n';
		}
	}
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	int start = 1;
	while (t--)
	{
		cout << "Case " << start << ":\n";
		GA();
		start++;
	}
	return 0;
}
