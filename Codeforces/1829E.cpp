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
const ll mod = 1e9+7;

void solve(){
	int n,m; read(n,m);
	vector<vector<int>> grid(n,vector<int>(m));
	for(auto& x : grid){
		for(auto& y : x){
			cin>>y;
		}
	}
	vector<vector<bool>> vis(n,vector<bool>(m,false));
	auto check = [&](int r, int c){
		return r>=0 && r<n && c>=0 && c<m &&  !vis[r][c] && grid[r][c]!=0;
	};

	vector<pair<int,int>> delta = {{1,0},{-1,0},{0,1},{0,-1}};

	int ans = 0;
	int sum = 0;
	function<void(int,int)> dfs = [&](int r, int c){
		vis[r][c] = true;
		sum+=grid[r][c];
		for(auto[dr,dc] : delta){
			int new_r = r+dr, new_c = c+dc;
			if(check(new_r,new_c)){
				dfs(new_r,new_c);
			}
		}
	};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(check(i,j)){
				dfs(i,j);
				ans = max(ans,sum);
				sum = 0;
			}
		}
	}
	cout<<ans<<'\n';
	
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
