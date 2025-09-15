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
const ll MX = 1e9+7;


bool prime(ll n){
	for(ll p = 2; p * p <= n; p++){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

void solve(){
	ll a, b; read(a, b);
	auto find = [&](ll x){
		for(int d = 2; d <= x / 2; d++){
			if(x % d == 0){
				ll m = 1, n = (x / d) - 1;
				ll a = d * m, b = d * n;
				if(__gcd(a, b) > 1){
					cout<< a << ' ' << b;
					ps();
					return;
				}
			}
		}
	};
	if(!prime(a)){
		find(a);
		return;
	}

	if(!prime(b)){
		find(b);
		return;
	}

	int num = 0;
	bool ok = 1;
	for(int i = a; i <= b; i++){
		if(!prime(i)){
			num = i;
			ok = 0;
			break;
		}
	}
	if(ok){
		ps(-1);
		return;
	}
	find(num);
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
