#include <bits/stdc++.h>
#include <cstddef>
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

void GA(){
	map<char, int> mp;
	string s; read(s);
	for(auto c : s){
		mp[c]++;
	}
	int n = s.size();
	string ga = string(2 * n, '0');
	for(int i = 2; i < 2 * n; i+=3){
		if(mp['P'] == 0) break;
		ga[i] = 'P';
		mp['P']--;
	}
	for(int i = 0; i < 2 * n; i++){
		if(ga[i] == 'P') continue;
		if(mp['C'] == 0) break;
		ga[i] = 'C';
		mp['C']--;
	}
	dbg(ga);
	string new_ga = "";
	for(int i = 0; i < n; i++){
		if(ga[i] != '0') new_ga.push_back(ga[i]);
	}
	dbg(new_ga);
	string target = "CCPC";
	int left = 0, right = 0, cn = 0;
	int xd = 0;
	while(right < n){
		xd++;
		if(xd > 4){
			xd--;
			left++;
		}
		if(right - left + 1 == 4){
			string res;
			for(int i = left; i <= right; i++){
				res+=new_ga[i];
			}
			if(res == target) cn++;
		}
		right++;
	}
	ps(cn);
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
