
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

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
		NEUTRAL = 0;
		tree.assign(2 * size, NEUTRAL);
		build(a, 0, 0, size);
	}

	T compare(const T& a, const T& b){
		return a + b;
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

	void modify(int pos, const T& val, int node, int left, int right){
		if(right - left == 1){
			tree[node] = val;
			return;
		}
		int mid = (left + right) >> 1;
		if(pos < mid) modify(pos, val, 2 * node + 1, left, mid);
		else modify(pos, val, 2 * node + 2, mid, right);
		tree[node] = compare(tree[2 * node + 1], tree[2 * node + 2]);
	}

	void modify(int pos, T val){
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

	T binary(int k, int node, int left, int right){
		if(right - left == 1){
			return left;
		}
		int mid = (right + left) >> 1;
		int sum = tree[2 * node + 1];
		if(k < sum) return binary(k, 2 * node + 1, left, mid);
		return binary(k - sum, 2 * node + 2, mid, right);
	}

	T binary(int k){
		return binary(k, 0, 0, size); 
	}
};



void UWU(){
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i <n; i++){
		cin >> a[i];
	}
	segmentTree<int> st(a);
	while(m--){
		int op; cin >> op;
		if(op == 1){
			int pos; cin >> pos;
			int val = st.query(pos, pos + 1);
			st.modify(pos, (val == 1 ? 0 : 1));
		}else{
			int k; cin >> k;
			cout << st.binary(k) << '\n';
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
