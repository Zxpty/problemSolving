#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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
const int MX = 1e5;

void GA(){
	long long n; read(n);
	vector<int> r(n);
	long long acc = 0;
	for(int i = 0; i < n; i++){
		cin >> r[i];
		acc += r[i];
	}
	long long sum = (n * (n + 1)) / 2;
	int cn = count(r.begin(), r.end(), 0);
	if(cn == 1){
		for(int i = 0; i < n; i++){
			if(r[i] == 0) r[i] = sum - acc;
		}
		int mn = 1;
		bool ok = 0;
		int left = 0;
		int right = 0;
		for(int i = 0; i < n; i++){
			if(r[i] != mn){
				if(!ok){
					left = i;
					ok = 1;
				}
				right = i;
			}
			mn++;
		}
		if(right == left){
			ps(0);
		}else ps(right - left + 1);
		return;
	}

	int mn = 1;
	int left_first = 0;
	int left_second = INT_MAX;
	int right_first = 0;
	int right_second = INT_MIN;
	bool ok1 = 0, ok2 = 0;
	for(int i = 0; i < n; i++){
		if(r[i] != mn){
			if(!ok1){
				left_first = i;
				ok1 = 1;
			}
			right_first = i;
		}
		if(r[i] == 0){
			if(!ok2){
				left_second = i;
				ok2 = 1;
			}
			right_second = i;
		}
		mn++;
	}
	//dbg(left_first, right_first);
	//dbg(left_second, right_second);
	int left = min(left_first, left_second);
	int right = max(right_first, right_second);
	if(left == right){
		ps(0);
	}else{
		ps(right - left + 1);
	}
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
