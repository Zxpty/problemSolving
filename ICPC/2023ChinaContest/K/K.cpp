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
const int MX = 1e5;

void GA(){
	int n, m; read(n, m);
	vector<vector<int>> r(m + 1, vector<int> (n + 1));
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> r[i][j];
		}
	}
	dbg(r);
	set<vector<int>> st;
	for(int i = 1; i <= m; i++){
		st.insert(r[i]);
	}

	auto merge = [&](vector<int>a, vector<int> b){
		vector<int> c(n + 1);
		for(int i = 1; i <= n; i++){
			c[i] = a[b[i]];
		}
		return c;

	};
	vector<vector<int>> k2;
	vector<int> k21 = merge(r[1], r[2]);
	vector<int> k22 = merge(r[1], r[3]);
	vector<int> k23 = merge(r[1], r[4]);
	vector<int> k24 = merge(r[2], r[3]);
	vector<int> k25 = merge(r[2], r[4]);
	vector<int> k26 = merge(r[3], r[4]);
	k2.push_back(k21);
	k2.push_back(k22);
	k2.push_back(k23);
	k2.push_back(k24);
	k2.push_back(k25);
	k2.push_back(k26);

	vector<vector<int>> k3;
	vector<int> k31 = merge(merge(r[1], r[2]), r[3]);
	vector<int> k32 = merge(merge(r[1], r[2]), r[3]);
	vector<int> k33 = merge(merge(r[1], r[2]), r[3]);
	vector<int> k34 = merge(merge(r[1], r[2]), r[3]);

	vector<int> first= merge(r[1], r[2]);
	vector<int> second = merge(first, r[3]);
	vector<int> third = merge(second, r[4]);
	int ans = 0;
	for(auto x : k2){
		if(st.count(x)) ans++; 
	}

	for(auto x : k3){
		if(st.count(x)) ans++;
	}

	if(st.count(third)) ans++;
	ps(ans);


	
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
