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
const int inf = 1e9+7;

struct seg_tree{
	int size;
	int Z = inf;
	vector<int> ans;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		ans.assign(2 * size, Z);
	}

	int op(int& a, int& b){
		return min(a, b);
	}
	void build(vector<int>& a, int node, int left, int right){
		if(right - left == 1){
			if(left < a.size()){
				ans[node] = a[left];
			}
			return;
		}
		int m = (left + right) >> 1;
		build(a, 2 * node + 1, left, m);
		build(a, 2 * node + 2, m, right);
		ans[node] = op(ans[2 * node + 1], ans[2 * node + 2]);
	}
	void build(vector<int>& a){
		build(a, 0, 0, size);
	}

	void set(int pos, int value, int node, int left, int right){
		if(right - left == 1){
			ans[node] = value;
			return;
		}
		int m = (left + right) >> 1;
		if(pos < m) set(pos, value, 2 * node + 1, left, m);
		else set(pos, value, 2 * node + 2, m, right);
		ans[node] = op(ans[2 * node + 1], ans[2 * node + 2]);
	}

	void set(int pos, int value){
		set(pos, value, 0, 0, size);
	}
	
	int query(int l, int r, int node, int left, int right){
		if(left >= r || right <= l) return Z;
		if(left >= l && right<= r) return ans[node];
		int m = (left + right) >> 1;
		int leftPart = query(l, r, 2 * node + 1, left, m);
		int rightPart = query(l, r, 2 * node + 2, m, right);
		return op(leftPart, rightPart);
	}

	int query(int l, int r){
		return query(l, r, 0, 0, size);
	}

};

void GA(){
	int n, q; read(n, q);
	vector<int> r(n); read(r);
	seg_tree st;
	st.init(n);
	st.build(r);
	while(q--){
		int type; read(type);
		if(type == 1){
			int pos, val; read(pos, val);
			st.set(pos, val);
		}else{
			int l, r; read(l, r);	
			cout << st.query(l, r) << '\n';
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
