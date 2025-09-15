#include <algorithm>
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
	int n, m, x, y; read(n, m, x ,y);
	x--, y--;
	vector<string> r(n); read(r);
	string s; read(s);
	int sz = (int) s.size();
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	auto check = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m && r[x][y] != '#';
	};
	vector<char> ans;
	char start = r[x][y];
	ans.push_back(r[x][y]);
	vis[x][y] = 1;
	for(int i = 0; i < sz; i++){
		if(s[i] == 'L'){
			y--;
			if(check(x, y)){
				if(!vis[x][y]){
					ans.push_back(r[x][y]);
					vis[x][y] = 1;
				}
			}else y++;
		}else if(s[i] == 'R'){
			y++;
			if(check(x, y)){
				if(!vis[x][y]){
					ans.push_back(r[x][y]);
					vis[x][y] = 1;
				}
			}else y--;
		}else if(s[i] == 'U'){
			x--;
			if(check(x, y)){
				if(!vis[x][y]){
					ans.push_back(r[x][y]);
					vis[x][y] = 1;
				}
			}else x++;
		}else if(s[i] == 'D'){
			x++;
			if(check(x,  y)){
				if(!vis[x][y]){
					ans.push_back(r[x][y]);
					vis[x][y] = 1;
				}
			}else x--;
		}
	}
	dbg(ans);
	int cn = count(ans.begin(), ans.end(), '@');
	if(start == '@') cn++;
	cout << x + 1 << " " << y + 1 << " " << cn;
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
