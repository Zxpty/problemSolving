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
const int MX = 1e5;

void GA(){
	int n; read(n);
	string s; read(s);
	int cn = count(s.begin(), s.end(), '0');
	if(cn == n){
		ps(cn / 2);
		return;
	}
	auto check = [&](int mn){
		int op = mn;
		string t = s;
		int l = 0;
		bool ok = 0;
		while(l < n){
			int r = l;
			while(r < n and t[r] == t[l]) r++;
			if(t[l] == '0'){
				for(int i = r - 1; i >= l; i-=2){
					if(op == 0){
						ok = 1;
						break;
					}
					t[i] = '1';
					op--;
				}
			}
			if(ok) break;
			l = r;
		}
		//dbg(mn);
		//dbg(t);
		int cnzero = 0;
		int cnone = 0;
		l = 0;
		while(l < n){
			int r = l;
			while(r < n and t[l] == t[r]) r++;
			if(t[l] == '1'){
				cnone += (r - l) / 2;
			}else{
				cnzero += (r - l) / 2;
			}
			l = r;
		}
		return cnone >= cnzero;
	};
	int ans = 0;
	int left = 0, right = n;
	while(left <= right){
		int mid = (right + left) / 2;
		if(check(mid)){
			right = mid - 1;
			ans = mid;
		}else{
			left = mid + 1;
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
		GA();
	}
	return 0;
}
