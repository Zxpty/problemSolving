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
	long long seg, pref, suff, sum;
};

template<typename T>
struct segmentTree {
	int size;
	vector<T> tree;
	T NEUTRAL;

	segmentTree() {}

	segmentTree(const vector<long long>& a){
		init(a);
	}

	void init(const vector<long long>& a){
		size = 1;
		while(size < int(a.size())) size <<= 1;
		NEUTRAL = {0, 0, 0, 0};
		tree.assign(2 * size, NEUTRAL);
		build(a, 0, 0, size);
	}

	T compare(const T& a, const T& b){
		long long seg = max({a.seg, b.seg, a.suff + b.pref});
		long long pref = max(a.pref, a.sum + b.pref);
		long long suff = max({b.suff, a.suff + b.sum});
		long long sum = a.sum + b.sum;
		return {seg, pref, suff, sum};
	}

	T add(long long val){
		if(val > 0) return {val, val, val, val};
		return {0, 0, 0, val};
	}

	void build(const vector<long long>& a, int node, int left, int right){
		if(right - left == 1){
			if(left < int(a.size())){
				tree[node] = add(a[left]);
			}
			return;
		}
		int mid = (left + right) >> 1;
		build(a, 2 * node + 1, left, mid);
		build(a, 2 * node + 2, mid, right);
		tree[node] = compare(tree[2 * node + 1], tree[2 * node + 2]);
	}

	void modify(int pos, long long val, int node, int left, int right){
		if(right - left == 1){
			tree[node] = add(val);
			return;
		}
		int mid = (left + right) >> 1;
		if(pos < mid) modify(pos, val, 2 * node + 1, left, mid);
		else modify(pos, val, 2 * node + 2, mid, right);
		tree[node] = compare(tree[2 * node + 1], tree[2 * node + 2]);
	}

	void modify(int pos, const long long& val){
		modify(pos, val, 0, 0, size);
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
	vector<long long> a(n);
	for(int i = 0; i <n; i++){
		cin >> a[i];
	}
	segmentTree<Node> st(a);

	cout << st.query(0, n).seg << '\n';
	while(m--){
		int pos;
		long long val;
		cin >> pos >> val;
		st.modify(pos, val);
		cout << st.query(0, n).seg << '\n';
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
