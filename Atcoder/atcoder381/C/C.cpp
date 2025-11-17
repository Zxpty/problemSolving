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

	int ans = 0;
	vector<int> one(n), two(n);
	one[0] = (s[0] == '1');
	two[0] = (s[0] == '2');
	for(int i = 1; i < n; i++){
		one[i] = one[i - 1] + (s[i] == '1');
		two[i] = two[i - 1] + (s[i] == '2');
	}
	auto getOne = [&](int l, int r){
		return one[r] - (l == 0 ? 0 : one[l - 1]);
	};
	auto getTwo = [&](int l, int r){
		return two[r] - (l == 0 ? 0 : two[l - 1]);
	};

	auto check = [&](int tam){
		int mid = tam / 2;
		for(int i = 0; i + tam - 1 < n; i++){
			int ones = getOne(i, i + mid - 1);
			int twos = getTwo(i + mid + 1, i + tam - 1);
			if(ones == mid && twos == mid && s[i + mid] == '/'){
				return true;
			}
		}
		return false;
	};


	int left = 1, right = n;
	while(left <= right){
		int mid = (right + left) / 2;
		if(mid % 2 == 0) mid--;
		if(check(mid)){
			ans = mid;
			left = mid + 2;
		}else{
			right = mid - 2;
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
		GA();
	}
	return 0;
}
