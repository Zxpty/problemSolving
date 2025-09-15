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
const long long MX = 1e9+7;

void GA(){
	int n; read(n);
	vector<int> r(n);
	long long sum = (n * (n + 1)) / 2;
	if(sum & 1){
		ps("NO");
		return;
	}

	sum /= 2;
	iota(allr(r), 1);
	long long acc = 0;
	set<int> st(r.begin(), r.end());
	set<int> ga;
	int pos = -1;
	int needed = -1;

	vector<int> suff(n);
	suff[n - 1] = r[n - 1];
	for(int i = n - 2; i >= 0; i--){
		suff[i] = suff[i + 1] + r[i];
	}

	for(int i = 0; i < n; i++){
		acc += r[i];
		ga.insert(r[i]);
		int need = sum - acc;
		if(ga.count(need) || need <= 0) continue;
		if(st.count(need)){
			needed = need;
			pos = i;
			break;
		}
	}
	vector<int> a, b;
	for(int i = 0; i <= pos; i++){
		a.push_back(r[i]);
	}
	a.push_back(needed);

	for(int i = pos + 1; i < n; i++){
		if(r[i] == needed) continue;
		b.push_back(r[i]);
	}

	ps("YES");
	ps(a.size());
	ps(a);
	ps(b.size());
	ps(b);
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
