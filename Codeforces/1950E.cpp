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
const int MX = 2e5 + 5;
vector<vector<int>> divs(MX);

void init(){
	for(int i = 1; i < MX; i++){
		for(int j = i; j < MX; j+=i){
			divs[j].emplace_back(i);
		}
	}
}

void solve(){
	int n; read(n);
	string s; read(s);
	if(n == 1){ps(1);return;}
	int res = n;
	auto check = [&](string s, int len){
		int cn = 0;
		int n = (int) s.size();
		for(int i = 0; i < len; i++){
			vector<int> freq(26);
			int mx = 0;
			for(int j = i; j < n; j+=len){
				mx = max(mx, ++freq[s[j] - 'a']);
			}
			cn+= n / len - mx;
			if(cn > 1) return false;
		}
		return cn <= 1;
	};
	for(int x : divs[n]){
		if(check(s, x)) res = min(res, x);
	}
	ps(res);
}

int main(){
	cpu();
	int t = 1;
	init();
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
