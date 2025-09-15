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
int n;
bool check(int row, int col, vector<int>& queens, vector<int> &columns,  vector<int> &diag1, vector<int> &diag2){
	if(columns[col]) return false;
	if(diag1[row - col + n - 1]) return false;
	if(diag2[row + col])  return false;
	return true;
}

int calc(int row, vector<int>& queens, vector<int> &columns, vector<int> &diag1, vector<int> &diag2){
	if(row == n) return 1;
	int ans = 0;
	for(int col = 0; col < n; col++){
		if(check(row, col, queens, columns, diag1, diag2)){
			queens.emplace_back(col);
			columns[col] = 1;
			diag1[row - col + n - 1] = 1;
			diag2[row + col] = 1;
			ans += calc(row + 1, queens, columns, diag1, diag2);
			columns[col] = 0;
			diag1[row - col + n - 1] = 0;
			diag2[row + col] = 0;
			queens.pop_back();
		}
	}
	return ans;
}

void GA(){
	read(n);
	vector<int> queens;
	vector<int> columns(n, 0);
	vector<int> diag1(2 * n - 1, 0);
	vector<int> diag2(2 * n - 1, 0);
	cout << calc(0, queens, columns, diag1, diag2);
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
