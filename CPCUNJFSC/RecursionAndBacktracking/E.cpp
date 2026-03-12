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

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);}
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.first, p.second);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.first, ", ", x.second, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.first, ' ', x.second); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}

const int MX = 1e9;
int n, k;
void solve(int x, int y, int size, bool white, vector<string>& grid, vector<string>& board){
	if(!white){
		for(int i = x; i < x + size; i++){
			for(int j = y; j < y + size; j++){
				grid[i][j] = '*';
			}
		}
		return;
	}

	if(size == 1){
		grid[x][y] = '.';
		return;
	}

	int cuadrante = size / n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(board[i][j] == '*'){
				solve(x + i * cuadrante, y + j * cuadrante, cuadrante, 0, grid, board);
			}else{
				solve(x + i * cuadrante, y + j * cuadrante, cuadrante, 1, grid, board);
			}
		}
	}
}

void ONO(){
	cin >> n >> k;
	vector<string> board(n); read(board);
	int N = 1;
	for(int i = 0; i < k; i++) N *= n;
	vector<string> grid(N, string(N, '.'));
	solve(0, 0, N, 1, grid, board);
	for(auto row : grid){
		ps(row);
	}
	

}

int main(){
	cpu();
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
