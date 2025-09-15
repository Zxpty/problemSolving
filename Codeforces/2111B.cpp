#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
const int MX = 80;

vector<int> dp(MX);

void init(){
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i < MX; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

void GA(){
	int n, m; read(n, m);
	while(m--){
		int w, l, h; read(w, l, h);
		bool ok = 0;
		vector<array<int, 3>> coord = {{w, l, h}, {w, h, l}, {l, h, w}, {h, w, l}, {h, l, w}};
		for(auto [a, b, c] : coord){
			if(a >= dp[n] && b >= dp[n] && c >= dp[n]){
				int need = dp[n];
				if(n >= 2) need += dp[n - 1];
				if(c >= need){
					long long tot = 1LL * a * b * c;
					long long use = 1LL * dp[n] * dp[n] * dp[n];
					if(n >= 2) use += 1LL * dp[n - 1] * dp[n - 1] * dp[n - 1];
					long long res = tot - use;
					long long need2 = 0;
					for(int i = 1; i <= n - 2; i++){
						need2 += 1LL * dp[i] * dp[i] * dp[i];
						//dbg(need2);
					}
					if(res >= need2){
						ok = 1;
						break;
					}
				}
			}
		}
		if(ok) cout << "1";
		else cout <<"0";
	}
	ps();
}

int main(){
	cpu();
	int t = 1;
	init();
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
