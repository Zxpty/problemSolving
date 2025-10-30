#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>

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
	vector<long long> r(n); read(r);
	sort(r.begin(), r.end());
	auto check = [&](int x){
		int idx = lower_bound(all(r), x) - r.begin();
		int good = n - idx;
		if(good >= x) return true;
		int need = x - good;
		vector<long long> p = r;
		long long div = 0;
		for(int i = 0; i < n; i++){
			if(p[i] % 2 == 0){
				if(p[i] >= x){
					while(p[i] % 2 == 0){
						p[i] /= 2;
						if(p[i] >= x) div++;
						else{
							p[i]*=2;
							break;
						}
					}
				}else{
					while(p[i] % 2 == 0){
						div++;
						p[i] /= 2;
					}
				}
			}
		}
		int complete = 0;
		sort(p.rbegin(), p.rend());
		dbg(p);
		for(int i = 0; i < n and complete < need; i++){
			if(p[i] >= x) continue;
			int needed = 0;
			while(p[i] < x){
				p[i] *= 2;
				needed++;
			}
			if(needed <= div){
				complete++;
				div -= needed;
			}else{
				break;
			}
		}
		dbg(p);
		return (complete >= need);
	};
	int left = 0, right = n;
	int ans = 0;
	while(left <= right){
		int mid = (right + left) / 2;
		if(check(mid)){
			ans = mid;
			left = mid + 1;
		}else{
			right = mid - 1;
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
