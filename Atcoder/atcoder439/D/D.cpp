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
	int n; read(n);
	vector<int> r(n); read(r);
	map<int, vector<int>> pos;
	for(int i = 0; i < n; i++){
		pos[r[i]].push_back(i);
	}
	long long ans = 0;
	for(auto [five, index] : pos){
		if(five % 5 == 0){
			int x = five / 5;
			int sev = 7 * x;
			int three = 3 * x;
			if(pos.count(sev) and pos.count(three)){
				vector<int> pos_sev = pos[sev];
				vector<int> pos_three= pos[three];
				for(int index_fiv : index){
					long long sev_left = lower_bound(pos_sev.begin(), pos_sev.end(), index_fiv) - pos_sev.begin();
					long long three_left = lower_bound(pos_three.begin(), pos_three.end(), index_fiv) - pos_three.begin();
					long long sev_right = int(pos_sev.size()) - sev_left;
					long long three_right = int(pos_three.size()) - three_left;
					ans += sev_left * three_left;
					ans += sev_right * three_right;
				}
			}
		}
	}
	ps(ans);
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
