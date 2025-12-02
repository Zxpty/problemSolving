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

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.first, p.second);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.first, ", ", x.second, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.first, ' ', x.second); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}


const int MX = 1e9;

void ONO(){
	int n; read(n);
	vector<int> a(n), b(n); read(a, b);
	int xa = 0, xb = 0;
	for(int x : a) xa ^= x;
	for(int x : b) xb ^= x;

	for(int i = 0; i < n; i++){
		int xora = xa ^ a[i];
		int xorb = xb ^ b[i];
		if(i % 2 == 0){
			if((xora ^ b[i]) > (xorb ^ a[i])){
				xa ^= a[i];
				xa ^= b[i];
				xb ^= b[i];
				xb ^= a[i];
				swap(a[i], b[i]);
			}
		}else{
			if((xorb ^ a[i]) > (xora ^ b[i])){
				xa ^= a[i];
				xa ^= b[i];
				xb ^= b[i];
				xb ^= a[i];
				swap(a[i], b[i]);
			}
		}
	}
	if(xb == xa){
		ps("Tie");
		return;
	}
	if(xa > xb){
		ps("Ajisai");
		return;
	}
	ps("Mai");
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
