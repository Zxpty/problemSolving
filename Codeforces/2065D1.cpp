#include <bits/stdc++.h>
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
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vii;

const ll MX = 1e9+7;

void GA(){
	int n, m; read(n, m);
	vector<vector<ll>> r(n, vector<ll>(m));
	vector<ll> sums(n, 0);
	vector<ll> preSum(n, 0);
	for(int i = 0; i < n; i++){
		ll sum = 0, pre_sum = 0;
		for(int j = 0; j < m; j++){
			cin>>r[i][j];
			sum+= r[i][j];
			pre_sum+= sum;
		}
		sums[i] = sum;
		preSum[i] = pre_sum;
	}
	vector<int> g(n);
	for(int i = 0; i < n; i++){
		g[i] = i;
	}
	auto check = [&](int a, int b){
		return sums[a] > sums[b];
	};
	sort(g.begin(), g.end(), check);
	dbg(g);
	ll ans = 0, acc = 0;
	for(int i = 0; i < n; i++){
		int pos = g[i];
		ans+= preSum[pos] + acc * m;
		acc+= sums[pos];
	}
	ps(ans);
		
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
