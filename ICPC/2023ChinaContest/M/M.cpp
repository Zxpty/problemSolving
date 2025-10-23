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
const int MX = 1e9;

void GA(){
	int n; read(n);
	vector<long long> a(n), b(n);
	for(int i = 0; i < n; i++){
		int x, y; read(x, y);
		a[i] = x;
		b[i] = y;
	}
	int median = (n + 1) / 2;
	long long left = 1, right = MX;
	long long ans = 1;
	auto check = [&](long long x){
		int initial_goods = 0;
		vector<int> ga(n);
		for(int i = 0; i < n; i++){
			bool ok = (a[i] >= x);
			bool ok2 = (b[i] >= x);
			if(ok) initial_goods++;
			if(ok and !ok2) ga[i] = -1;
			else if(!ok and ok2) ga[i] = 1;
			else ga[i] = 0;
		}
		int mx = 0, curr = 0;
		for(auto x : ga){
			curr = max(0, curr + x);
			mx = max(curr, mx);
		}
		return initial_goods + mx >= median;
	};
	while(left <= right){
		long long mid = (right + left) / 2;
		if(check(mid)){
			ans = mid;
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
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
