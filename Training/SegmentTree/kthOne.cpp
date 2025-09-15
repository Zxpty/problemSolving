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

struct seg{
	int size;
	vector<int> ans;
	int NEUTRAL = 0;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		ans.resize(2 * size);
	}
	int op(int a, int b){
		return a + b;
	}

	int single(int value){
		return value;
	}

	void build(vector<int>& a, int node, int left, int right){
		if(right - left == 1){
			if(left < (int) a.size()){
				ans[node] = single(a[left]);
			}
			return;
		}
		int mid = (right + left) >> 1;
		build(a, 2 * node + 1, left, mid);
		build(a, 2 * node + 2, mid, right);
		ans[node] = op(ans[2 * node + 1], ans[2 * node + 2]);
	}
	void build(vector<int>& a){
		build(a, 0, 0, size);
	}

	void modify(int pos, int value, int node, int left, int right){
		if(right - left == 1){
			ans[node] = single(value);
			return;
		}
		int mid = (right + left) >> 1;
		if(pos < mid) modify(pos, value, 2 * node + 1, left, mid);
		else modify(pos, value, 2 * node + 2, mid, right);
		ans[node] = op(ans[2 * node + 1], ans[2 * node + 2]);
	 }
	void modify(int pos, int value){
		modify(pos, value, 0, 0, size);
	}

	int query(int l, int r, int node, int left, int right){
		if(left >= r || l >= right) return NEUTRAL;
		if(left >= l && right <= r) return ans[node];
		int mid = (right + left) >> 1;
		int sumLeft = query(l, r, 2 * node + 1, left, mid);
		int sumRight = query(l, r, 2 * node + 2, mid, right);
		return op(sumLeft, sumRight);
	}
	int query(int l, int r){
		return query(l, r, 0, 0, size);
	}

	int find(int k, int node, int left, int right){
		if(right - left == 1){
			return left;
		}
		int mid = (right + left) >> 1;
		int sl = ans[2 * node + 1];
		if(k < sl)return find(k, 2 * node + 1, left, mid);
		return find(k - sl, 2 * node + 2, mid, right);
	}
	int find(int k){
		return find(k, 0, 0, size);
	}
};

void GA(){
	int n, q; read(n, q);
	vector<int> r(n); read(r);
	seg st;
	st.init(n);
	st.build(r);

	while(q--){
		int type; read(type);
		if(type == 1){
			int pos; read(pos);
			r[pos] = 1 - r[pos];
			st.modify(pos, r[pos]);
		}else{
			int k; read(k);
			cout << st.find(k) << '\n';
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
