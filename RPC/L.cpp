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
	int n, c; read(n, c);
	vector<pair<int, pair<int, int>>> r(c);
	for(int i = 0; i < c; i++){
		int first; read(first);
		char a, b; read(a, b);
		r[i] = {first, {a, b}};
	}
	vector<char> p(n);
	for(int i = 0; i < n; i++){
		p[i] = ('A' + i);
	}

	vector<map<char, int>> permutations;
	do{
		map<char, int> mp;
		for(int i = 0; i < n; i++){
			mp[p[i]] = i;
		}
		permutations.push_back(mp);
	}while(next_permutation(p.begin(), p.end()));

	int cn = 0;
	for(auto x : permutations){
		bool ok = 1, ok1 = 1, ok2 = 1;
		for(auto res : r){
			int type = res.first; 
			char letterA = res.second.first;
			char letterB = res.second.second;
			if(type == 1){
				if(x[letterA] > x[letterB]) ok = 0;
			}else if(type == 2){
				if(x[letterB] > x[letterA]) ok1 = 0;
			}else{
				if(abs(x[letterA] - x[letterB]) == 1) ok2 = 0;
			}
		}
		if(ok && ok1 && ok2) cn++;
	}
	ps(cn);
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
