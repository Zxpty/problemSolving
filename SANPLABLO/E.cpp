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

long long solve(vector<int>& comp, int high, vector<int>& e, pair<int, int> range){
	long long sum = 0;
	int m = int(comp.size());
	long long ans = 0;
	vector<int> freq(high);
	freq[0] = 1;
	int last = -1;
	vector<int> before;
	for(int i = 0; i < m; i++){
		sum += comp[i];
		sum %= high;
		int now = range.first + i;
		if(e[now] == 1){
			for(long long x : before){
				freq[x]++;
			}
			before.clear();
			ans += freq[sum];
			before.push_back(sum);
			last = i;
		}else{
			if(last != -1){
				ans += freq[sum];
			}
			before.push_back(sum);
		}
	}
	return ans;
}


void GA(){
	int n; read(n);
	vector<int> r(n); read(r);
	auto get = [&](int x){
		int val = x;
		int mx = 0;
		while(val > 0){
			int digit = val % 10;
			mx = max(mx, digit);
			val /= 10;
		}
		return mx;
	};
	
	map<int, int> mx;
	for(int i = 0; i < n; i++){
		mx[r[i]] = get(r[i]);
	}
	
	long long ans = 0;
	for(int i = 1; i <= 9; i++){
		vector<int> e(n);
		for(int j = 0; j < n; j++){
			if(mx[r[j]] == i) e[j] = 1;
			else if(mx[r[j]] < i) e[j] = 0;
			else e[j] = -1;
		}
		
		int left = 0;
		vector<vector<int>> components;
		int id = 1;
		map<int, pair<int, int>> mp;
		while(left < n){
			while(left < n && e[left] == -1) left++;
			int right = left;
			while(right < n && e[right] != -1) right++;
			vector<int> xd;
			for(int j = left; j < right; j++){
				xd.push_back(r[j]);
			}
			components.push_back(xd);
			mp[id] = {left, right};
			id++;
			left = right;
		}
		int m = int(components.size());
		for(int j = 0; j < m; j++){
			ans += solve(components[j], i, e, mp[j + 1]);
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
