#include <bits/stdc++.h>
#include <queue>
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
const ll MX = 1e9+7;
void solve(){
	int n; read(n);
	ll total_sum = 1LL * (n*(n+1)) / 2;
	if(total_sum & 1){
		ps("NO");
		return;
	}
	ll mit = 1LL * total_sum / 2;
	ll mitad = mit;
	vector<bool> freq(n + 1, false);
	vector<int> fs;
	int num = n;
	while(mit - num > 0){
		mit-= num;
		num--;
		fs.push_back(num);
		freq[num] = true;
	}
	ll sum = 0;
	for(int i = 0; i < (int)fs.size(); i++){
		sum+= fs[i];
	}
	fs.push_back(mitad - sum);
	freq[mitad - sum] = 1;
	vector<int> sc;
	
	for(int i = 1; i <=n; i++){
		if(!freq[i]){
			sc.push_back(i);
		}
	}
	ps("YES");
	ps((int)fs.size());
	for(int i = 0; i < (int) fs.size(); i++) cout<<fs[i]<<' ';
	ps();
	ps((int)sc.size());
	for(int i = 0; i < (int) sc.size(); i++) cout<<sc[i]<<' ';
	ps();
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
