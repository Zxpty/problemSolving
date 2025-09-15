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
const ll MX = 1e9+7;

void GA(){
	int n; read(n);
	vector<int> r(n - 2); read(r);
	int m = n - 2;
	int mx = 1e2 + 5;
	vector<int> a(n, mx);
	int temp = 2;
	for(int i = 0; i + 1 < m; i++){
		if(r[i] == 1){
			for(int j = i; j < i + 3 && j < n - 1; j++){
				if(a[j] == mx){
					a[j] = temp;
				}
			}
			if(r[i + 1] != r[i]) temp++;
		}
	}
	if(r[m - 1] == 1 && r[m - 2] == 1){
		a[n - 1] = a[n - 2];
	}
	dbg(a);
	for(int i = 0; i < m; i++){
		if(r[i] == 1){
			for(int j = i + 1; j < i + 3 && j <  n - 1; j++){
				if(a[j] != a[j - 1]){
					ps("NO");
					return;
				}
			}
		}
	}
	ps("YES");
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
