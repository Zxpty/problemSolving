#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
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


typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vii;
typedef int64_t i64;
const ll MX = 1e9+7;

const long long xn = 7e6 + 1;

vector<pair<long long, long long>> r;
map<long long, long long> mp;
void pre(){
	for(long long i = 1; i <= xn; i++){
		long long sum = (i * (i + 1)) / 2;
		r.emplace_back(sum, i);
		mp[sum] = i;
	}
}


void GA(){
	long long n; read(n);
	auto check = [&](long long n){
		long long left = 0, right = n / 2;
		while(left <= right){
			long long mid = (right + left) / 2;
			if((mid * (mid + 1)) == 2 * n){
				return true;
			}
			if(mid * (mid + 1) < 2 * n){
				left = mid + 1;
			}else right = mid - 1;
		}
		return false;
	};
	vector<pair<long long, long long>> ans;
	for(int i = 0; i < (int) r.size(); i++){
		if(check(r[i].first + n) && (r[i].first + n) - r[i].first == n){
			ans.push_back({r[i].first + n, r[i].second});
		}
	}
	auto xd = [&](const auto a, const auto b){
		return a.second > b.second;
	};
	sort(ans.begin(), ans.end(), xd);
	ps(ans.size());
	for(int i = 0 ;i < (int)ans.size(); i++){
		if(ans[i].second < mp[ans[i].first] && ans[i].second > 0 && mp[ans[i].first] > 0){
			cout<< ans[i].second << " " << mp[ans[i].first] << '\n';
		}
	}
}

int main(){
	cpu();
	int t = 1;
	pre();
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

