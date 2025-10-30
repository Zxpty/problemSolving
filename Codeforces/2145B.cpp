#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>

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
const int MX = 1e5;

void GA() {
    int n, k; read(n, k);
    string s; read(s);
	if(n == 1 and k == 1 and s[0] == 2){
		ps('-');
		return;
	}
	int c0 = 0, c1 = 0, c2 = 0;
	for(int i = 0;i  < k; i++){
		if(s[i] == '0') c0++;
		else if(s[i] == '1') c1++;
		else c2++;
	}
	if(n == k){
		string p(n, '-');
		ps(p);
		return;
	}
	vector<char> p(n, '+');
	int left = 0, right = n - 1;
	for(int i = 0; i < k; i++){
		if(c0 > 0){
			p[i] = '-';
			c0--;
			left = i + 1;
		}
	}

	for(int i = n - 1; i >= 0; i--){
		if(c1 > 0){
			p[i] = '-';
			c1--;
			right = i - 1;
		}
	}
	while(c2--){
		if(left <= right){
			p[left++] = '?';
			p[right--] = '?';
		}
	}
	for(auto c : p){
		cout << c;
	}
	ps();
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
