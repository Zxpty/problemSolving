#include <algorithm>
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);}
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.first, p.second);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.first, ", ", x.second, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.first, ' ', x.second); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}

const int MX = 1e9;

void ONO(){
	long long w, h; read(w, h);
	int y0; read(y0);
	vector<int> y00(y0); read(y00);
	int yh; read(yh);
	vector<int> yhh(yh); read(yhh);
	int x0; read(x0);
	vector<int> x00(x0); read(x00);
	int xw; read(xw);
	vector<int> xww(xw); read(xww);

	long long ans = 0;
	long long mx = *max_element(x00.begin(), x00.end());
	long long mn = *min_element(x00.begin(), x00.end());
	ans = max(ans, (mx - mn) * w);

	mx = *max_element(xww.begin(), xww.end());
	mn = *min_element(xww.begin(), xww.end());
	ans = max(ans, (mx - mn) * w);

	mx = *max_element(y00.begin(), y00.end());
	mn = *min_element(y00.begin(), y00.end());
	ans = max(ans, (mx - mn) * h);

	mx = *max_element(yhh.begin(), yhh.end());
	mn = *min_element(yhh.begin(), yhh.end());
	ans = max(ans, (mx - mn) * h);

	ps(ans);

}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}

