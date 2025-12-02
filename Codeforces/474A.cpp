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
	string first = "qwertyuiop";
	string second = "asdfghjkl;";
	string third = "zxcvbnm,./";
	map<char, char> mp_left;
	map<char, char> mp_right;
	for(int i = 1; i < 10; i++)mp_left[first[i]] = first[i - 1];
	for(int i = 1; i < 10; i++)mp_left[second[i]] = second[i - 1];
	for(int i = 1; i < 10; i++)mp_left[third[i]] = third[i - 1];
	for(int i = 0; i + 1 < 10; i++) mp_right[first[i]] = first[i + 1];
	for(int i = 0; i + 1 < 10; i++) mp_right[second[i]] = second[i + 1];
	for(int i = 0; i + 1 < 10; i++) mp_right[third[i]] = third[i + 1];

	char type; read(type);
	string s; read(s);
	if(type == 'L'){
		for(int i = 0; i < int(s.size()); i++){
			s[i] = mp_right[s[i]];
		}
	}else{
		for(int i = 0; i < int(s.size()); i++){
			s[i] = mp_left[s[i]];
		}
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
