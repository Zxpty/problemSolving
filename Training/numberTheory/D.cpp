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
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vii;
typedef int64_t i64;
const int mx = 1e5+7;
vector<int> lp(mx), primes;
void sieve(){
	for(int k = 2; k <= mx; k++){
		if(lp[k] == 0){
			lp[k] = k;
			primes.push_back(k);
		}
		for(int i = 0; i < primes.size(); i++){
			int p = primes[i];
			if(p > lp[k]) break;
			int m = p * k;
			if(m > mx) break;
			lp[m] = p;
		}
	}
}
bool prime(ll n){
	if(n <= 1) return false;
	for(ll p = 2; p * p <= n; p++){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

void GA(){
	int n; read(n);
	int ans = 0;
	for(int x : primes){
		if(!prime(n + x)){
			ans = x;
			break;
		}
	}
	ps(ans);

}

int main(){
	cpu();
	int t = 1;
	sieve();
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
