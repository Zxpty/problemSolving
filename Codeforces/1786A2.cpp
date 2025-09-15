#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
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
const ll inf = 1e9+7;

void solve(){
	long long n; read(n);
	long long cn = 0;
	long long left = 0, right = inf;
	while(left <= right){
		long long mid = left + ( right - left ) / 2;
		long long sum = (mid * ( mid + 1 ))  / 2;
		if( sum <= n ){
			cn = mid;
			left = mid + 1;
		}else {
			right = mid - 1;
		}
	}
	vector<long long> r;
	r.push_back(1);
	for(int i = 2; i <= cn; i+=2){
		r.push_back(i+1 + i);
	}
	long long bob_w = 0, bob_b = 0, alice_w = 1, alice_b = 0;
	long long pos = 0;
	int sz = (int)r.size();
	for(int i = 1; i < sz; i++){
		if(i%2 == 0){
			alice_w+= ceil(r[i]/2);
			alice_b+= r[i] - ceil(r[i] / 2);
		}else{
			bob_w+= r[i]/2;
			bob_b+= r[i] - (r[i]/2);

		}
		pos = i;
	}
	dbg(alice_w,alice_b,bob_w,bob_b);
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
