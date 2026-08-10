#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

struct Node{
	int mx_first, mx_second, freq_first, freq_second;
};

template<typename T>
struct segmentTree {
	int n, size;
	vector<T> tree;
	T NEUTRAL;

	T combine(const T& a, const T& b) const {
		int first = max(a.mx_first, b.mx_first);
		int second = -1;
		vector<int> vals = {a.mx_first, a.mx_second, b.mx_first, b.mx_second};
		vector<int> freq = {a.freq_first, a.freq_second, b.freq_first, b.freq_second};
		for(int i = 0; i < 4; i++){
			if(vals[i] < first && vals[i] > second){
				second = vals[i];
			}
		}
		int count_first = 0;
		int count_second = 0;
		for(int i = 0; i < 4; i++){
			if(vals[i] == first){
				count_first += freq[i];
			}else if(vals[i] == second && second != -1){
				count_second += freq[i];
			}
		}
		return {first, second, count_first, count_second};
	}

	segmentTree() : n(0), size(0), NEUTRAL(0) {}

	segmentTree(int n, T nuetral_val) : n(n), NEUTRAL(nuetral_val){
		size = 1;
		while(size < n) size <<= 1;
		tree.assign(2 * size, NEUTRAL);
	}

	segmentTree(const vector<T>& a, T neutral_val) : NEUTRAL(neutral_val){
		init(a);
	}

	void init(const vector<T>& a){
		n = static_cast<int>(a.size());
		size = 1;
		while(size < n) size <<= 1;
		tree.assign(2 * size, NEUTRAL);
		build(a, 0, 0, size);
	}

	void build(const vector<T>& a, int node, int left, int right){
		if(right - left == 1){
			if(left < n){
				tree[node] = a[left];
			}
			return;
		}
		int mid = (left + right) >> 1;
		build(a, 2 * node + 1, left, mid);
		build(a, 2 * node + 2, mid, right);
		tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
	}

	void update(int pos, const T& val, int node, int left, int right){
		if(right - left == 1){
			tree[node] = val;
			return;
		}
		int mid = (left + right) >> 1;
		if(pos < mid) update(pos, val, 2 * node + 1, left, mid);
		else update(pos, val, 2 * node + 2, mid, right);
		tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
	}

	void update(int pos, T val){
		update(pos, val, 0, 0, size);
	}

	T query(int l, int r, int node, int left, int right) const {
		if(left >= r || right <= l) return NEUTRAL;
		if(left >= l && right <= r) return tree[node];
		int mid = (left + right) >> 1;
		return combine(query(l, r, 2 * node + 1, left, mid),
				query(l, r, 2 * node + 2, mid, right));
	}

	T query(int l, int r) const {
		return query(l, r, 0, 0, size);
	}

	T kth_element(int k, int node, int left, int right) const {
		if(right - left == 1){
			return left;
		}
		int mid = (right + left) >> 1;
		int val = tree[2 * node + 1];
		if(k < val) return kth_element(k, 2 * node + 1, left, mid);
		return kth_element(k - val, 2 * node + 2, mid, right);
	}

	T kth_element(T k) const {
		return kth_element(k, 0, 0, size); 
	}

	int find_first(T x, int l, int node, int left, int right) const {
		if(tree[node] < x || right <= l) return -1;
		if(right - left == 1) return left;

		int mid = (left + right) >> 1;
		int res = find_first(x, l, 2 * node + 1, left, mid);
		if(res != -1) return res;
		return find_first(x, l, 2 * node + 2, mid, right);
	}

	int find_first(T x, int l = 0) const {
		return find_first(x, l, 0, 0, size);
	}
};

void UWU(){
	int n, m; cin >> n >> m;
	vector<int> r(n);
	for(int& x : r) cin >> x;
	
	vector<Node> a(n);
	for(int i = 0; i < n; i++){
		a[i].mx_first = r[i];
		a[i].mx_second = -1;
		a[i].freq_first = 1;
		a[i].freq_second = 0;
	}

	segmentTree<Node> st(a, {-1, -1, 1, 0});

	for(int i = 0; i < m; i++){
		int op; cin >> op;
		if(op == 1){
			int pos, val; cin >> pos >> val;
			st.update(pos - 1, {val, -1, 1, 0});
		}else{
			int left, right; cin >> left >> right;
			Node res = st.query(left - 1, right);
			if(res.mx_second == -1){
				cout << 0 << '\n';
			}else{
				cout << res.freq_second << "\n";
			}
		}
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
