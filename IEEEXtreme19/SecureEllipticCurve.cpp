#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>

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


typedef long long i64;
const int MX = 1e5;

i64 modInverse(i64 a, i64 p){
	a %= p;
	if(a < 0) a += p;
	i64 b = p, u = 1, v = 0;
	while(b){
		i64 t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	if(u < 0) u += p;
	return u;
}

void GA(){
	i64 a, b, p;
	i64 x1, y1, x2, y2;
	read(a, b, p, x1, y1, x2, y2);
	bool inf;
	auto addPoint = [&](i64 a, i64 b, i64 p, i64 x1, i64 y1, i64 x2, i64 y2, bool &inf){
		inf = 0;
		if(x1 == x2 and (y1 + y2) % p == 0){
			inf = 1;
			return make_pair(0LL, 0LL);
		}
		i64 m;
		if(x1 == x2 and y1 == y2){
			i64 numerator = (3 * x1 % p * x1 % p + a) % p;
			i64 denominator = (2 * y1) % p;
			m = numerator * modInverse(denominator, p) % p;
		}else{
			i64 numerator = (y2 - y1) % p;
			if(numerator < 0) numerator += p;
			i64 denominator = (x2 - x1) % p;
			if(denominator < 0) denominator += p;
			m = numerator * modInverse(denominator, p) % p;
		}

		i64 x3 = (m * m - x1 - x2) % p;
		if(x3 < 0) x3 += p;

		i64 y3 = (m * (x1 - x3) - y1) % p;
		if(y3 < 0) y3 += p;
		return make_pair(x3, y3);
	};
	auto [x3, y3] = addPoint(a, b, p, x1, y1, x2, y2, inf);
	if(inf) ps("POINT_AT_INFINITY");
	else ps(x3, y3);
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
