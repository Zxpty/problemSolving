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
template<typename T>
struct seg_tree {
	int N;
	T Z = 0;
	vector<T> tree;
	
	seg_tree(int N) : N(N) {
		tree.resize(4 * N); 
	}
	
	seg_tree(vector<T>& A) {
		N = (int)A.size();
		tree.resize(4 * N);
		build(A, 1, 0, N-1);
	}
	
private:
	T op(T a, T b) {
		return a + b;
	}
	
	void build(vector<T>& a, int node, int left, int right) {
		if(left == right) {
			tree[node] = a[left];
			return;
		}
		int mid = (left + right) >> 1;
		build(a, 2 * node, left, mid);
		build(a, 2 * node + 1, mid + 1, right);
		tree[node] = op(tree[2 * node], tree[2 * node + 1]);
	}
	
	void modify(int pos, T value, int node, int left, int right) {
		if(left == right) {
			tree[node] = value;
			return;
		}
		int mid = (left + right) >> 1;
		if(pos <= mid) 
			modify(pos, value, 2 * node, left, mid);
		else 
			modify(pos, value, 2 * node + 1, mid + 1, right);
		tree[node] = op(tree[2 * node], tree[2 * node + 1]);
	}
	
	T query(int l, int r, int node, int left, int right) {
		if(r < left || l > right) return Z;
		if(l <= left && right <= r) return tree[node];
		int mid = (left + right) >> 1;
		T leftSum = query(l, r, 2 * node, left, mid);
		T rightSum = query(l, r, 2 * node + 1, mid + 1, right);
		return op(leftSum, rightSum);
	}
	
public:
	void build(vector<T>& a) { build(a, 1, 0, N-1); }
	void modify(int pos, T value) { modify(pos, value, 1, 0, N-1); }
	T query(int l, int r) { return query(l, r, 1, 0, N-1); }
};
void GA(){
	multiset<int> st;
	int q; read(q);
	while(q--){
		int type; read(type);
		if(type == 1){
			int x; read(x);
			st.insert(x);
		}else{
			if(st.empty()) continue;
			ps(*st.begin());
			st.erase(st.find(*st.begin()));
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
