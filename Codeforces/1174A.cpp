#include <bits/stdc++.h>
#include <future>
#include <numeric>
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
const ll MX = 1e9+7;

void solve(){
	int n; read(n);
	vector<int> r(n * 2); read(r);

	ll mit1 = 0, mit2 = 0;
	for(int i = 0; i < n; i++){
		mit1+=r[i];
	}
	for(int i = n; i < (2 * n); i++){
		mit2+=r[i];
	}
	if(mit1 != mit2){
		for(int x : r) cout<< x << ' ';
		ps();
		return;
	}
	sort(r.begin(), r.end());
	reverse(r.begin() + n, r.end());
	swap(r[n - 1],r[(2 * n) - 1]);

	mit1 = 0, mit2 = 0;
	for(int i = 0; i < n; i++){
		mit1+=r[i];
	}
	for(int i = n; i < (2 * n); i++){
		mit2+=r[i];
	}
	dbg(mit1, mit2);
	if(mit1 != mit2){
		for(int x : r) cout<< x << ' ';
		ps();
	}else{
		ps(-1);
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
