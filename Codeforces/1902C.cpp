#include <algorithm>
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);}
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
	vector<long long> r(n); read(r);
	if(n == 1){
		ps(1);
		return;
	}
	long long x = abs(r[1] - r[0]);
	for(int i = 1; i < n - 1; i++){
		x = __gcd(x, abs(r[i + 1] - r[i]));
	}

	long long ans_first = 0;
	long long first = *max_element(r.begin(), r.end()) + x;
	set<long long> s;
	for(int i = 0; i < n; i++){
		ans_first += (first - r[i]) / x;
		s.insert(r[i]);
	}
	dbg(first);

	first = *max_element(r.begin(), r.end()) - x;
	dbg(first);
	while(s.count(first)){
		first -= x;
	}
	dbg(first);
	long long second = *max_element(r.begin(), r.end());
	dbg(second);
	long long ans_second = (second - first) / x;
	dbg(ans_second);
	for(int i = 0; i < n; i++){
		ans_second += (second - r[i]) / x;
	}
	ps(min(ans_first, ans_second));
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
