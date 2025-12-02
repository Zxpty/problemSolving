#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/branch_policy/traits.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>

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


vector<int> sieve(int n){
	vector<int> prime(n + 1, true);
	prime[0] = prime[1] = false;
	vector<int> dp(n + 1);
	iota(dp.begin(), dp.end(), 0);
	for(int i = 2; i * i <= n; i++){
		if(prime[i]){
			for(int j = i * i; j <= n; j += i){
				prime[j] = false;
				dp[j] = i;
			}
		}
	}
	return dp;
}



void ONO(){
	int n; read(n);
	vector<int> r = sieve(n);
	vector<pair<int, int>> ans;
	for(int i = 1; i <= n; i++){
		ans.emplace_back(r[i], i);
	}

	sort(r.begin(), r.end());
	n++;
	int left = 2;
	map<int, int> mp;
	while(left < n){ 
		int right = left; //dbg(right);
		while(right < n && r[left] == r[right])right++;
		//dbg(r[left]);
		if(right - left == 1){
			mp[r[left]]++;
		}
		left = right;
	}
	sort(ans.begin(), ans.end(), [&](auto a, auto b){
			if(a.first == b.first){
			return a.second < b.second;
			}
			return a.first < b.first;
			});

	vector<int> p;
	for(auto [_, val] : ans){
		if(mp[val] == 0) p.push_back(val);
	}
	p.erase(p.begin());
	cout << "1 ";

	vector<int> need;
	//dbg(mp);
	for(auto x : mp){
		if(x.second == 1) need.push_back(x.first);
	}
	//dbg(need);
	int m = p.size();
	int q = need.size();
	int idx = 0;
	for(int i = 0; i < m; i++){
		if(i % 2 == 1){
			if(idx < q){
				cout << need[idx] << " ";
				idx++;
			}
		}
		cout << p[i] << " ";
	}

	while(idx < q){
		cout << need[idx] << " ";
		idx++;
	}
	ps();
	

}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
