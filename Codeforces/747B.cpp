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

void ONO(){
	int n; read(n);
	string s; read(s);
	if(n % 4 != 0){
		ps("===");
		return;
	}

	vector<int> r(5);
	vector<int> pos;
	for(int i = 0; i < n; i++){
		if(s[i] == 'A') r[0]++;
		if(s[i] == 'C') r[1]++;
		if(s[i] == 'T') r[2]++;
		if(s[i] == 'G') r[3]++;
		if(s[i] == '?') pos.push_back(i);
	}
	for(int i = 0; i < 4; i++){
		if(r[i] > (n / 4)){
			ps("===");
			return;
		}
	}
	int start = 0;
	for(int i = r[0]; i < n / 4; i++){
		s[pos[start]] = 'A';
		start++;
	}

	for(int i = r[1]; i < n / 4; i++){
		s[pos[start]] = 'C';
		start++;
	}

	for(int i = r[2]; i < n / 4; i++){
		s[pos[start]] = 'T';
		start++;
	}

	for(int i = r[3]; i < n / 4; i++){
		s[pos[start]] = 'G';
		start++;
	}

	ps(s);

	
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

	


