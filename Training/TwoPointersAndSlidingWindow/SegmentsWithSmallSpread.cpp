#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <shared_mutex>

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


typedef int64_t i64;
const long long MX = 1e9+7;

struct stack{
	vector<long long> s, smin = {LLONG_MAX}, smx = {LLONG_MIN};
	void push(long long x){
		s.push_back(x);
		smin.push_back(::min(smin.back(), x));
		smx.push_back(::max(smx.back(), x));
	}

	long long pop(){
		long long res = s.back();
		s.pop_back();
		smin.pop_back();
		smx.pop_back();
		return res;
	}

	bool empty(){
		return s.empty();
	}

	long long min(){
		return smin.back();
	}

	long long max(){
		return smx.back();
	}

};

::stack s1, s2;


void add(long long x){
	s2.push(x);
}

void remove(){
	if(s1.empty()){
		while(!s2.empty()){
			s1.push(s2.pop());
		}
	}
	s1.pop();
}

long long k;

bool good(){
	long long mn = min(s1.min(), s2.min());
	long long mx = max(s1.max(), s2.max());
	return mx - mn <= k;
}

void GA(){
	long long n; read(n, k);
	vector<long long> r(n); read(r);
	long long left = 0, right = 0, ga = 0;
	while(right < n){
		add(r[right]);
		while(!good()){
			remove();
			left++;
		}
		ga += right - left + 1;
		right++;
	}
	ps(ga);
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
