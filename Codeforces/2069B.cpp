#include <bits/stdc++.h>
#include <functional>
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
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vii;
typedef int64_t i64;
const int MX = 1e9+7;

void GA() {
	int n, m; read(n, m);
	vector<vector<int>> r(n, vector<int>(m));
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>r[i][j];
			mp[r[i][j]]++;
		}
	}
	bool ok = 1;
	for(auto x : mp){
		
	}
	int sz = (int)mp.size();
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, - 1}};
	auto check = [&](int nr, int nc, int start){
		return (nr >= 0 && nr < n && nc >=0 && nc < m && !vis[nr][nc] && r[nr][nc] == start);
	};
	function<int(int ,int, int)> dfs = [&](int x, int y, int value){
		vis[x][y] = 1;
		int cn = 1;
		for(auto [dr, dc] : delta){
			int nr = x + dr;
			int nc = y + dc;
			if(check(nr, nc, value)){
				cn+= dfs(nr, nc, value);
			}
		}
		return cn;
	};
	int mx = 0, found = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j]){
				int op = dfs(i, j, r[i][j]);
				if(op > mx){
					mx = op;
					found = r[i][j];
				}
			}
		}
	}
	//dbg(mx, found);
	vis.assign(n, vector<bool>(m, false));
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(r[i][j] != found && !vis[i][j]){
				int op = dfs(i, j, r[i][j]);
				//dbg(r[i][j], op);
				if(op == 1) continue;
				else {
					ans+=op;
					mp[r[i][j]]-=op;
				}
			}
		}
	}
	for(auto x : mp){
		if(x.first != found && x.second > 0){
			ans++;
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
