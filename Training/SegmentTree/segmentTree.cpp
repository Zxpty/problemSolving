#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;

template<typename T>
struct segment_tree{
	int N;
	vector<T> tree;
	segment_tree(int N) : N(N){
		tree.resize(2 * N);
	}
	segment_tree(vector<T>& A){
		N = (int) A.size();
		tree.resize(2 * N);
		build(A, 1, 0, N - 1);
	}
	auto& operator[](size_t i) { return tree[i]; } // this funciton works for get element int this position
	T op(T& a, T& b){
		return a + b;
	}
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
			dbg(l, r, node, tree[node]);
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
	void modify(int pos, int value, int node,  int l,  int r){
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
	// O(log N)
	T query(int ql, int qr, int node, int l, int r){
		if(r < ql || l > qr) return T(0);
		if(ql <= l && r <= qr) return tree[node];
		int m = (l + r) >> 1;
		int left = node + 1;
		int right = node + 2 * (m - l + 1);
		T ansL = query(ql, qr, left, l, m);
		T ansR = query(ql, qr, right, m + 1, r);
		return op(ansL, ansR);
	}

	void build(vector<T>& values){ build(values, 1, 0, N - 1); }
	void modify(int pos, int value){ modify(pos, value, 1, 0, N - 1); }
	T query(int ql, int qr){ return query(ql, qr, 1, 0, N - 1); }

};

void GA(){
	vector<long long> A = {2, 3, 1, 7, 5, 8, 3, 2, 5, 1};
	int n = 10;
	segment_tree<long long> st(A);
	cout << st.query(1, 5) << '\n';
	st.modify(3, 10);
	cout << st.query(1, 5)<< '\n';
	cout << st[1] << '\n';
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
