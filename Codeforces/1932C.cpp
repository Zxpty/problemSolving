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
	int mod;
	T Z = 1;
	vector<T> tree;
	segment_tree(int N) : N(N) {
		tree.resize(2 * N);
	}

	segment_tree(vector<T>& A, int MOD){
		N = (int) A.size();
		mod = MOD;
		tree.resize(2 * N);
		build(A, 1, 0, N - 1);
	}

private:
	T op(T& a, T& b){ return a * b; }
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
		
		tree[node] = op(tree[left], tree[right]) % mod;
	}
	
	T query(int ql, int qr, int node, int l, int r){
		if(r < ql || l > qr) return Z; 
		if(ql <= l && r <= qr) return tree[node];
		int m = (l + r) >> 1;
		int left = node + 1;
		int right = node + 2 * (m - l + 1);
		T ansL = query(ql, qr, left, l, m);
		T ansR = query(ql, qr, right, m + 1, r);
		return op(ansL, ansR) % mod;
	}
public:
	void build(vector<T>& values){ build(values, 1, 0, N - 1); }
	T query(int ql, int qr){ return query(ql, qr, 1, 0, N - 1); }
};



void ONO(){
	int n, m; read(n, m);
	vector<int> r(n); read(r);
	string s; read(s);
	segment_tree<int> st(r, m);
	int left = 0, right = n - 1;
	for(int i = 0; i < n; i++){
		cout << st.query(left, right) % m << " ";
		s[i] == 'L' ? left++ : right--;
	}
	ps();

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
