#include <algorithm>
#include <bits/stdc++.h>
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
typedef vector<int> vi;
const ll mod = 1e9+7;

void solve(){
	long long n; read(n);
	vector<long long> r(n);read(r);
	sort(r.begin(),r.end());
	int exclude = 0;
	int mx = 0;
	map<int,int> mp;
	for(int i = 0; i < n; i++){
		exclude^=r[i];
		mp[r[i]]++;
		mx = max(mx, exclude);
	}
	if(mp[mx] == 0){
		long long ans = accumulate(r.begin(),r.end(),0);
		ps(ans);
		return;
	}
	int cn = 0;
	long long sum = 0;
	long long mx2 = mx;
	long long sc = mx;
	for(int i = 0; i < n; i++){
		sc = max(sc,(mx2^r[i]));
	}
	for(int i = 0; i < n; i++){
		if(r[i] <= sc){
			sum+=sc;
		}else sum+=r[i];
	}
	ps(sum);
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
