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

const ll MX = 1e9+7;
const int mxn = 1005;
void GA(){
	int n; read(n);
	vector<int> r(n); read(r);
	map<int,int> mp;
	for(int i = 0; i < n; i++)mp[r[i]]++;
	if((int)mp.size() > n / 2){
		ps("NO");
		return;
	}
	if((int)mp.size() == 1){
		for(auto x : mp){
			if(x.second % 2 == 0){
				ps("YES");
				return;
			}
		}
		ps("NO");
		return;
	}
	bool ok = 1;
	for(auto x : mp){
		if(x.second % 2 != 0){
			ok = 0;
			break;
		}
	}
	if(ok){
		ps("YES");
		return;
	}
	vector<pair<int,int>> v;
	for(auto x : mp){
		v.push_back({x.first, x.second});
	}
	sort(v.begin(), v.end());
	int mn = v[0].second;
	int smn = v[1].second;
	if(mn == 1 ){
		ps("NO");
		return;
	}
	int mid = n / 2;
	if(mn == mid){
		if(mn % 2 == 0){
			ps("YES");
		}else{
			ps("NO");
		}
	}else{
		ps("YES");
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
