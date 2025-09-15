#include <algorithm>
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

void printN(int n){
	if(n == 0) return;
	cout << n << ' ';
	printN(n - 1);
}

int sum(vector<int>& r, int n){
	if(n == 0) return 0;
	return r[n - 1] + sum(r, n - 1);
}

int maxNum(vector<int>& r, int n){
	if(n == 1) return r[0];
	return max(r[n - 1], maxNum(r, n - 1));
}

string invertir(string s){
	int n = s.size();
	if(n == 1 || n == 0) return s;
	return s[n - 1] + invertir(s.substr(0, n - 1));
}

void invertirS(string s){
	int n = s.size();
	if(n == 0) return;
	invertirS(s.substr(1));
	cout << s[0];
}

int countNumber(vector<int>& r, int n, int x){
	if(n == 0) return 0;
	if(r[n - 1] == x) return 1 + countNumber(r, n - 1, x);
	else return countNumber(r, n - 1, x);
}

void GA(){
	int n = 5;
	vector<int> r = {2, 3, 2, 5, 2};
	int x = 2;
	cout << countNumber(r, 5, x);
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
