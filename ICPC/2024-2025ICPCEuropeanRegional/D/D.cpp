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

void GA(){
	int n; read(n);
	vector<long long> r(n); read(r);
	map<long long, long long> mp;
	stack<pair<long long, int>> st;
	/*
	for(int i = 0; i < n; i++){
		long long mn = MX;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			if(r[j] > r[i]){
				long long op = abs(j - i);
				mn = min(mn, op);
			}
		}
		if(mn == MX)continue;
		mp[r[i]] = mn;
	}
	long long sum = 0;
	for(auto x : mp){
		sum+=x.second;
	}
	dbg(sum);
	dbg(mp); */
	for(int i = 0; i < n; i++){
		while(!st.empty() && st.top().first < r[i]){
			long long num = st.top().first;
			long long dis = abs(i - st.top().second);
			if(mp.count(num)){
				if(dis < mp[num]) mp[num] = dis;
			}else mp[num] = dis;
			st.pop();
		}
		st.emplace(r[i], i);
	}
	for(int i = n - 1; i >= 0; i--){
		while(!st.empty() && st.top().first < r[i]){
			long long num = st.top().first;
			long long dis = abs(i - st.top().second);
			if(mp.count(num)){
				if(dis < mp[num]) mp[num] = dis;
			}else mp[num] = dis;
			st.pop();
		}
		st.emplace(r[i], i);
	}
	long long sum = 0;
	for(auto x : mp) sum+= x.second;
	ps(sum);
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
