#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

struct segmentTree {
	int size;
	vector<long long> tree;

	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(2 * size, 0LL);
	}

	void build(vector<int>& a, int node, int left, int right){
		if(right - left == 1){
			if(left < int(a.size())){
				tree[node] = a[left];
			}
			return;
		}
		int mid = (left + right) >> 1;
		build(a, 2 * node + 1, left, mid);
		build(a, 2 * node + 2, mid, right);
		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}

	void build(vector<int>& a){
		build(a, 0, 0, size);
	}

	void set(int pos, int val, int node, int left, int right){
		if(right - left == 1){
			tree[node] = val;
			return;
		}
		int mid = (left + right) >> 1;
		if(pos < mid){
			set(pos, val, 2 * node + 1, left, mid);
		}else{
			set(pos, val, 2 * node + 2, mid, right);
		}
		tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
	}

	void set(int pos, int val){
		set(pos, val, 0, 0, size);
	}

	long long sum(int l, int r, int node, int left, int right){
		if(left >= r || right <= l) return 0;
		if(left >= l && right <= r) return tree[node];
		int mid = (left + right) >> 1;
		long long leftSum = sum(l, r, 2 * node + 1, left, mid);
		long long rightSum = sum(l, r, 2 * node + 2, mid, right);
		return leftSum + rightSum;
	}

	long long sum(int l, int r){
		return sum(l, r, 0, 0, size);
	}
};



void UWU(){
	int n, m; cin >> n >> m;
	segmentTree st;
	st.init(n);
	vector<int> r(n);
	for(int& x : r) cin >> x;
	st.build(r);
	while(m--){
		int op; cin >> op;
		if(op == 1){
			int i, v; cin >> i >> v;
			st.set(i, v);
		}else{
			int left, right; cin >> left >> right;
			cout << st.sum(left, right) << '\n';
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
