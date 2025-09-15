#include <bits/stdc++.h>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

using u64 = uint64_t;
using u128 = __uint128_t;

typedef long long ll;

u64 add(u64 a, u64 b, u64 mod) { return (u128)(a + b) % mod; }
u64 mul(u64 a, u64 b, u64 mod) { return (u128) a * b % mod; }
u64 bpow(u64 a, u64 e, u64 mod) {
    u64 r = 1;
    a %= mod;
    while (e) {
        if (e & 1) r = mul(r, a, mod);
        a = mul(a, a, mod);
        e >>= 1;
    }
    return r;
}

u64 string_num(string s, u64 mod) {
    u64 res = 0;
    for (char c : s) {
        res = (res * 10 + (c - '0')) % mod;
    }
    return res;
}

bool check(u64 n, u64 a, u64 d, int s) {
    u64 x = bpow(a, d, n);
    if (x == 1 or x == n - 1) return 0;
    for (int r = 1; r < s; r++) {
        x = mul(x, x, n);
        if (x == n - 1) return 0;
    }
    return 1;
};

bool miller_rabin(string s) {
	u64 n = string_num(s, ULLONG_MAX);
    if (n < 2) return 0;
    int r = 0;
    u64 d = n - 1;
    while (d % 2 == 0) d >>= 1, r++;
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return 1;
        if (check(n, a, d, r)) return 0;
    }
    return 1;
}


void GA(){
	int n, k; read(n, k);
	if(n == 1){
		ps("NO");
		return;
	}
	string xs = to_string(n);
	if(k == 1){
		if(miller_rabin(xs)){
			ps("YES");
		}else{
			ps("NO");
		}
		return;
	}
	string y = "";
	for(int i = 0; i < k; i++) y+=xs;
	if((y.back() - '0') % 2 == 0){
		ps("NO");
		return;
	}
	if(miller_rabin(y)){
		ps("YES");
		return;
	}
	ps("NO");
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
