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

void GA(){
	int zero, one, k; read(zero, one, k);
	dbg(zero, one, k);
	int mx = max(zero, one);
	int mn = min(zero, one);
	if(k > mx){
		ps(-1);
		return;
	}
	int bloq1 = zero/ k;
	int bloq2 = one / k;
	int rest1 = zero % k;
	int rest2 = one % k;
	bool ok = 0;
	if(bloq1 == bloq2){
		if(rest1 > rest2){
				for(int i = 0; i < bloq1; i++){
					cout<< string(k, '0') << string(k, '1');
				}
				cout<<string(rest1,'0')<< string(rest2, '1');
				ps();
		}else{
				for(int i = 0; i < bloq1; i++){
					cout<< string(k, '1') << string(k, '0');
				}
				cout<<string(rest2,'1')<< string(rest1, '0');
				ps();
		}
	}else if(bloq1 == bloq2 + 1){
		if(rest1 > rest2){ ps(-1); return;}
		for(int i = 0; i < bloq2; i++){
			cout<< string(k, '0') << string(k, '1');
		}
		cout<< string(k, '0') << string(rest2, '1') << string(rest1, '0');
		ps();
	}else if(bloq2 == bloq1 + 1){
		if(rest2 > rest1){ ps(-1); return;}
		for(int i = 0; i < bloq1; i++){
			cout<< string(k, '1') << string(k, '0');
		}
		cout<< string(k, '1') << string(rest1, '0') << string(rest2, '1');
		ps();

	}else{
		ps(-1);
		return;
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
