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
	int k, n, m; read(k, n, m);
	vector<int> p(n), c(m); read(p), read(c);
	int p_start = 0;
	int c_start = 0;
	vector<int> ans;
	while(p_start < min(n, m)){
		if(p[p_start] == 0){
			ans.push_back(0);
			ans.push_back(c[c_start]);
		}else if(c[c_start] == 0){
			ans.push_back(0);
			ans.push_back(p[p_start]);
		}else if(p[p_start] == 0 && c[c_start] == 0){
			ans.push_back(0);
			ans.push_back(0);
		}else{
			if(p[p_start] > c[c_start]){
				ans.push_back(c[c_start]);
				ans.push_back(p[p_start]);
			}else{
				ans.push_back(p[p_start]);
				ans.push_back(c[c_start]);
			}
		}
		p_start++;
		c_start++;
	}
	//while(p_start < n && c_start < m){
	//}
	if(n > m){
		while(p_start < n){
			ans.push_back(p[p_start]);
			p_start++;
		}
	}else{
		while(c_start < m){
			ans.push_back(c[c_start]);
			c_start++;
		}
	}

	bool ok = 1;
	for(int i = 0; i < n + m; i++){
		if(ans[i] == 0) k++;
		else{
			if(ans[i] > k){
				ok = 0;
				break;
			}
		}
	}
	if(ok){
		for(int i = 0; i < n + m; i++){
			cout<< ans[i] << ' ';
		}
		ps();
	}else{
		ps(-1);
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
