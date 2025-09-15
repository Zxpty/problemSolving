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
typedef vector<long long> vl;
typedef vector<pair<int,int>> vii;
typedef int64_t i64;
const ll MX = 1e9+7;

template<class T>
struct segment_tree{
	int n; 
	vector<T> tree;

	segment_tree(int n){
		this -> n = n;
		tree.resize(2 * n);
	}

	segment_tree(vector<T>& values){
		this -> n = values.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) upd(i, values[i]);
	}
	
	//CHANGE
	T compare(T a, T b){
		return a + b;
	}

	void modify(int index, T value){
		index += n;
		tree[index] = value;
		for(index >>= 1; index >= 1; index >>= 1) tree[index]= compare(tree[2 * index], tree[2 * index + 1]);
	}

	void upd(int index, T value){
		index += n;
		tree[index] = compare(tree[index], value);
		for(index >>= 1; index >= 1; index >>= 1) tree[index]= compare(tree[2 * index], tree[2 * index + 1]);
	}
	
	//BOTTOM - TOP
	T query(int first, int last){
		first += n, last += n;
		T ans = 0;
		while(first <= last){
			if(first % 2 == 1) ans = compare(ans, tree[first++]);
			if(last % 2 == 0) ans = compare(ans, tree[last--]);
			first >>= 1, last >>= 1;
		}
		return ans;
	}
};

void GA(){
	int n, q; read(n, q);

	
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
