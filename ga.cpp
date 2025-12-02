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

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
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


void ONO(){
	vector<int> r = {3, 2, 8, 5, 4, 14, 9, 15};
	int start = r[0];
	for(int i = 1; i < r.size(); i++){
		start ^= r[i];
	}
	ps(start);
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
