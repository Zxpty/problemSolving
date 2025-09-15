#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

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

long long compute_hash(string const& s){
	const int p = 31;
	const int m = 1e9 + 9;
	long long hash_value = 0;
	long long p_pow = 1;
	for(char c : s){
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hash_value;
}

vector<vector<int>> group_identical_strings(vector<string> const& s){
	int n = int(s.size());
	vector<pair<long long, int>> hashes(n);
	for(int i = 0; i < n; i++)
		hashes[i] = {compute_hash(s[i]), i};
	sort(hashes.begin(), hashes.end());
	vector<vector<int>> groups;
	for(int i = 0;i < n; i++){
		if(i == 0 || hashes[i].first != hashes[i - 1].first)
			groups.emplace_back();
		groups.back().push_back(hashes[i].second);
	}
	return groups;
}

vector<int> rabink_karp(string const& s, string const& t){
	const int p = 31;
	const int m = 1e9 + 9;
	int S = int(s.size()), T = int(t.size());
	vector<long long> p_pow(max(S, T));
	p_pow[0] = 1;
	for(int i = 1; i < int(p_pow.size()); i++){
		p_pow[i] = (p_pow[i - 1] * p) % m;
	}
	vector<long long> h(T + 1, 0);
	for(int i = 0; i < T; i++){
		h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
	}
	long long h_s = 0;
	for(int i = 0; i < S; i++){
		h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
	}
	vector<int> occurrences;
	for(int i = 0; i + S - 1 < T; i++){
		long long cur_h = (h[i + S] + m - h[i]) % m;
		if(cur_h == h_s * p_pow[i] % m) occurrences.push_back(i);
	}
	return occurrences;
}

void GA(){
	int n;
	string s, t;
	while(cin >> n >> s >> t){
		vector<int> ans = rabink_karp(s, t);
		if(ans.empty()) ps();
		else {
			for(int x : ans){
				ps(x);
			}
		}
	}
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
