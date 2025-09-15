#include <bits/stdc++.h>
#include <future>
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

const ll MX = 1e9+7;

void GA(){
	int n; read(n);
	vii r(n);
	for(int i = 0; i < n; i++){
		int a, b; read(a, b);
		if(b > a)swap(a, b);
		r[i].first = a;
		r[i].second = b;
	}
	if(n == 1){
		ps((2 * r[0].first) + (2 * r[0].second));
		return;
	}
	auto px = [&](const pair<int,int>& a, const pair<int,int>& b){
		if(a.first == b.first){
			return a.second > b.second;
		}
		return a.first < b.first;
	};

	sort(r.rbegin(), r.rend());
	int a = 0, b = 0;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		auto [f, s] = r[i];
		ll first = 1LL * ((f - a) + (2LL * s));
		ll op = first;
		sum+=op;
	}
	ps(sum);
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
