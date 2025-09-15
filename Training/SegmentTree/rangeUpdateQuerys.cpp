#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
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


typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vii;
typedef int64_t i64;
const ll MX = 1e9+7;

template<typename T>
struct segment_tree{
	int N;
	T Z = 0;
	vector<T> tree;
	segment_tree(int N) : N(N) {
		tree.resize(2 * N);
	}

	segment_tree(vector<T>& A){
		N = (int) A.size();
		tree.resize(2 * N);
		build(A, 1, 0, N - 1);
	}

	auto& operator[](size_t i) { return tree[i]; } // this funciton works for get element int this position
												   //
private:

	T op(T& a, T& b){ return a + b; }
	// O (n)
	void build(vector<T>& values, int node, int l, int r){
		// if l and r are equal both are leaf node
		// left node = [l, m]
		// m = (l + r) / 2
		// left and right are nodes
		// left interval = [l, m], right intervla = [m + 1, r]
		// after complete fill nodes of left and right, we need to fill the [l, r] node
		if(l == r){
			tree[node] = values[l];
			return;
		}
		int m = (l + r) >> 1;
		int left = node + 1;
		int right = node + 2 * (m - l + 1);

		build(values, left, l, m);
		build(values, right, m + 1, r);
		
		tree[node] = op(tree[left], tree[right]);
	}
	
	// O (log N)
	void modify(int pos, T value, int node,  int l,  int r){
		// if l and r are equal, we found our node and update it
		if(l == r){
			tree[node] = value;
			return;
		}
		int m = (l + r) >> 1; // we get the mid
		int left = node + 1;
		int right = node + 2 * (m - l + 1);

		if(pos <= m) modify(pos, value, left, l, m);
		else modify(pos, value, right, m + 1, r);

		tree[node] = op(tree[left], tree[right]);
	}

	void update(int pos, T value, int node,  int l,  int r){
		// if l and r are equal, we found our node and update it
		if(l == r){
			tree[node] = op(tree[node], value);
			return;
		}
		int m = (l + r) >> 1; // we get the mid
		int left = node + 1;
		int right = node + 2 * (m - l + 1);

		if(pos <= m) update(pos, value, left, l, m);
		else update(pos, value, right, m + 1, r);

		tree[node] = op(tree[left], tree[right]);
	}

	// O(log N)
	T query(int ql, int qr, int node, int l, int r){
		if(r < ql || l > qr) return Z; // CHECK
		if(ql <= l && r <= qr) return tree[node];
		int m = (l + r) >> 1;
		int left = node + 1;
		int right = node + 2 * (m - l + 1);
		T ansL = query(ql, qr, left, l, m);
		T ansR = query(ql, qr, right, m + 1, r);
		return op(ansL, ansR);
	}
public:
	void build(vector<T>& values){ build(values, 1, 0, N - 1); }

	void modify(int pos, T value){ modify(pos, value, 1, 0, N - 1); }

	void update(int pos, T value){ update(pos, value, 1, 0, N - 1); }

	T query(int ql, int qr){ return query(ql, qr, 1, 0, N - 1); }
};

void GA(){
	int n, q; cin >> n >> q;
	vector<long long> a(n);
	for(long long& x : a) cin>> x;
	vector<long long> b(n);
	b[0] = a[0];
	for(int i = 1; i < n; i++){
		b[i] = a[i] - a[i - 1];
	}
	segment_tree<long long> st(b);
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int l, r; cin >> l >> r; l--, r--;
			long long u; cin >> u;
			st.update(l, u);
			if(r + 1 < n) st.update(r + 1, -u);
		}else{
			int k; read(k); k--;
			cout << st.query(0, k) << '\n';
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
