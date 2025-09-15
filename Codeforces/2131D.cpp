#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ios>
#include <string>

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

void GA(){
	long long k; read(k);
	long long sum = 0;
	long long d = 1;
	long long start = 1;

	auto ga = [&](long long n){
		if(n <= 0) return 0LL;
		long long res = 0, factor = 1;
		while(factor <= n){
			long long right = n / (factor * 10);
			long long curr = (n / factor) % 10;
			long long left = n % factor;
			res += right * 45 * factor;
			res += (curr * (curr - 1) / 2) * factor;
			res += curr * (left + 1);
			factor *= 10;
		}
		return res;
	};

	while(true){
		long long cn = 9 * start;
		long long dig = cn * d;
		if(k > dig){
			long long end = start * 10 - 1;
			sum += ga(end) - ga(start - 1);
			k -= dig;
		}else{
			long long cal = k / d;
			long long end = start + cal - 1;
			if(cal > 0){
				sum += ga(end) - ga(start - 1);
			}
			long long res = k % d;
			if(res > 0){
				long long ga = start + cal;
				string s = to_string(ga);
				for(int i = 0; i < res; i++) sum += s[i] - '0';
			}
			break;
		}
		start *= 10;
		d++;
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

