#include <algorithm>
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
const ll mod = 1e9+7;

struct Node{
	int val;
	bool OR;
	Node(){val = 0, OR = true;}
	Node(int val, bool OR) : val(val), OR(OR){}
};

template<typename T>
struct segment_tree{
	int N;
	T Z = Node();
	vector<T> tree;
	
	segment_tree() {}

	segment_tree(int N) : N(N) {
		tree.resize(2 * N);
	}

	segment_tree(vector<T>& A){
		N = (int) A.size();
		tree.resize(2 * N);
		build(A, 1, 0, N - 1);
	}

	auto& operator[](size_t i) { return tree[i]; }

private:

	T op(T& a, T& b){
		T ret;
		ret.OR = !a.OR;
		if(ret.OR) ret.val = (a.val | b.val);
		else ret.val = (a.val ^ b.val);
		return ret;
	}

	// O(N)
	void build(vector<T>& values, int node, int l, int r){
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
	
	// O(log N)
	void modify(int pos, T value, int node, int l, int r){
		if(l == r){
			tree[node] = value;
			return;
		}
		int m = (l + r) >> 1;
		int left = node + 1;
		int right = node + 2 * (m - l + 1);

		if(pos <= m) modify(pos, value, left, l, m);
		else modify(pos, value, right, m + 1, r);

		tree[node] = op(tree[left], tree[right]);
	}

	void update(int pos, T value, int node, int l, int r){
		if(l == r){
			tree[node] = op(tree[node], value);
			return;
		}
		int m = (l + r) >> 1;
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

void solve(){
	int n, q; read(n, q);
	vector<int> r(1 << n); read(r);
	vector<Node> values(1 << n);
	for(int i = 0; i < (1 << n); i++){
		values[i].val = r[i];
		values[i].OR = 0;
	}
	segment_tree<Node> st(values);
	while(q--){
		int pos,b; read(pos, b);
		pos--;
		st.modify(pos, Node(b, false));
		ps(st[1].val);
	}
}


int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
