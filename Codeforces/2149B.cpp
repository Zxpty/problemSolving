#include <bits/stdc++.h>
#include <climits>
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

void GA(){
	int n; read(n);
	vector<int> r(n); read(r);
	sort(r.begin(), r.end());
	int mn = INT_MIN;
	for(int i = 0; i + 1 < n; i+=2){
		mn = max(mn, r[i + 1] - r[i]);
	}
	ps(mn);
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
