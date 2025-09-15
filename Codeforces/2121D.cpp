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

void GA(){
	int n; read(n);
	vector<int> a(n), b(n); read(a, b);
	vector<pair<char, int >> ans;

	auto inseSort = [&](vector<int>& ga, char type, bool rev = false, bool need = false){
		for(int i = 1; i < n; i++){
			if(!need){
				if(ga[i] < b[i - 1]){
					int j = i;
					while(j > 0 && ((!rev && ga[j] < ga[j - 1]) || (rev && ga[j] > ga[j - 1]))){
						swap(ga[j], ga[j - 1]);
						ans.emplace_back(type, j);
						j--;
					}
				}
			}else{
					int j = i;
					while(j > 0 && ((!rev && ga[j] < ga[j - 1]) || (rev && ga[j] > ga[j - 1]))){
						swap(ga[j], ga[j - 1]);
						ans.emplace_back(type, j);
						j--;
					}
			}
		}
	};
	inseSort(a, '1');
	inseSort(b, '2', true);
	for(int i = 0; i < n; i++){
		if(a[i] > b[i]){
			swap(a[i], b[i]);
			ans.emplace_back('3', i + 1);
		}
	}
	inseSort(a, '1', false, true);
	inseSort(b, '2', false, true);
	dbg(a);
	dbg(b);
	cout << int(ans.size()) << '\n';
	for(auto [x, y] : ans){
		cout << x << " " <<  y << "\n";
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
