

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
	int mn, cnt;
};

template<typename T>
struct segmentTree {
	int size;
	vector<T> tree;
	T NEUTRAL;

	segmentTree() {}

	segmentTree(const vector<T>& a){
		init(a);
	}

	void init(const vector<T>& a){
		size = 1;
		while(size < int(a.size())) size <<= 1;
		NEUTRAL = {INT_MAX, 0};
		tree.assign(2 * size, NEUTRAL);
		build(a, 0, 0, size);
	}

	T compare(const T& a, const T& b){
		if(a.mn < b.mn) return a;
		if(a.mn > b.mn) return b;
		return {a.mn, a.cnt + b.cnt};
	}

	void build(const vector<T>& a, int node, int left, int right){
		if(right - left == 1){
			if(left < int(a.size())){
				tree[node] = a[left];
			}
			return;
		}
		int mid = (left + right) >> 1;
		build(a, 2 * node + 1, left, mid);
		build(a, 2 * node + 2, mid, right);
		tree[node] = compare(tree[2 * node + 1], tree[2 * node + 2]);
	}

	void build(const vector<int>& a){
		build(a, 0, 0, size);
	}

	void set(int pos, const T& val, int node, int left, int right){
		if(right - left == 1){
			tree[node] = val;
			return;
		}
		int mid = (left + right) >> 1;
		if(pos < mid) set(pos, val, 2 * node + 1, left, mid);
		else set(pos, val, 2 * node + 2, mid, right);
		tree[node] = compare(tree[2 * node + 1], tree[2 * node + 2]);
	}

	void set(int pos, const T& val){
		set(pos, val, 0, 0, size);
	}

	T query(int l, int r, int node, int left, int right){
		if(left >= r || right <= l) return NEUTRAL;
		if(left >= l && right <= r) return tree[node];
		int mid = (left + right) >> 1;
		return compare(query(l, r, 2 * node + 1, left, mid),
				query(l, r, 2 * node + 2, mid, right));
	}

	T query(int l, int r){
		return query(l, r, 0, 0, size);
	}
};



void UWU(){
	int n, m; cin >> n >> m;
	vector<Node> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].mn;
		a[i].cnt = 1;
	}
	segmentTree<Node> st(a);

	while(m--){
		int op; cin >> op;
		if(op == 1){
			int i, v; cin >> i >> v;
			st.set(i, {v, 1});
		}else{
			int left, right; cin >> left >> right;
			auto ans = st.query(left, right);
			cout << ans.mn << " " << ans.cnt << "\n";
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
