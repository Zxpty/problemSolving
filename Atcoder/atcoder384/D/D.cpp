#include <bits/stdc++.h>
#include <iterator>
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
	ll n, target; read(n, target);
	vector<long long> r(n); read(r);
	long long sum = 0;
	int left = 0, right = 0;
	for(int i = 0; i < n; i++){
		sum+= r[i];
		if(sum >= target){
			right = i;
			while(sum > target && left < right){
				sum-=r[left];
				left++;
			}
			if(target % sum == 0){
				ps("Yes");
				return;
			}
		}
	}

	long long sum_ = accumulate(r.begin(), r.end(), 0LL);
	if(target % sum_ == 0){
		ps("Yes");
		return;
	}
	set<ll> st;
	st.insert(0);
	long long prefijo = 0;
	for(int i = 0; i < n; i++){
		prefijo+=r[i];
		st.insert(prefijo % sum);
	}
	long long sufijo = 0;
	for(int i = n - 1; i >= 0; i--){
		sufijo+= r[i];
		long long p = ((target - sufijo) % sum);
		if(st.find(p) != st.end()){
			ps("Yes");
			return;
		}
	}
	ps("No");

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
