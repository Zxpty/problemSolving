#include <algorithm>
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
const ll mod = 1e9+7;

void solve(){
	int n, m; read(n, m);
	vector<vector<int>> r(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> r[i][j];
		}
	}
	auto check = [&](int x, int y){
		return x >= 0 and x < n and y >= 0 and  y < m;
	};
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int x = i, y = j;
			int sum = r[i][j];
			x--,y--;
			while(check(x, y)){
				sum += r[x][y];
				x--, y--;
			}
			x = i, y = j;

			x++, y++;
			while(check(x, y)){
				sum += r[x][y];
				x++, y++;
			}

			x = i, y = j;
			x--, y++;
			while(check(x, y)){
				sum += r[x][y];
				x--, y++;
			}

			x = i, y = j;
			x++, y--;
			while(check(x, y)){
				sum += r[x][y];
				x++, y--;
			}
			//dbg(i, j, vis);
			ans = max(ans, sum);
		}
	}
	ps(ans);
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
