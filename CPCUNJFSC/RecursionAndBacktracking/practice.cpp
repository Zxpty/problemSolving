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

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
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

int sumar(vector<int> a, int left, int right){
	if(left == right) return a[left];
	int mid = (left + right) / 2;
	int left_sum = sumar(a, left, mid);
	int right_sum = sumar(a, mid + 1, right);
	return left_sum + right_sum;
}

int max_element(vector<int> a, int left, int right){
	if(left == right) return a[left];
	int mid = (left + right) / 2;
	int left_max = max_element(a, left, mid);
	int right_max = max_element(a, mid + 1, right);
	return max(left_max, right_max);
}

int search_element(vector<int> a, int left, int right, int target){
	if(left == right){
		return a[left] == target;
	}
	int mid = (right + left) / 2;
	int found_left = search_element(a, left, mid, target);
	if(found_left) return 1;
	int found_right = search_element(a, mid + 1, right, target);
	if(found_right) return 1;
	return 0;
}

void ONO(){
	int n; read(n);
	vector<int> r(n); read(r);
	int ans = sumar(r, 0, n - 1);
	ps(ans);
	int mx = max_element(r, 0, n - 1);
	ps(mx);
	int ok = search_element(r, 0, n - 1, 2);
	if(ok)ps("Elemento encontrado");
	else ps("Elemento no encontrado");
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
