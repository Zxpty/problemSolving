#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

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


bool check(vector<vector<int>>& grid, int row, int col, int num, int n){
	for(int i = 0; i < n * n; i++){
		if(grid[i][col] == num) return false;
	}

	for(int j = 0; j < n * n; j++){
		if(grid[row][j] == num) return false;
	}

	int rowStart = n * (row / n);
	int colStart = n * (col / n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(grid[rowStart + i][colStart + j] == num) return false;
		}
	}
	return true;
}


bool solve(vector<vector<int>>& grid, int n){
	int SIZE = n * n;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(grid[i][j] == 0){
				for(int num = 1; num <= SIZE; num++){
					if(check(grid, i, j, num, n)){
						grid[i][j] = num;
						if(solve(grid, n)) return true;
						grid[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}


void ONO(){
}

int main(){
	cpu();
	bool test = true;
	int n;
	while(cin >> n){
		if(!test) cout << '\n';
		test = false;
		int n; read(n);
		int SIZE = n * n;
		vector<vector<int>> grid(SIZE, vector<int>(SIZE));
		read(grid);
		bool solu = solve(grid, n);
		if(!solu) ps("NO SOLUTION");
		else{
			for(int i = 0; i < SIZE; i++){
				for(int j = 0; j < SIZE; j++){
					cout << grid[i][j];
					if(j + 1 < SIZE) cout << ' ';
				}
				if(i + 1 < SIZE) cout << '\n';
			}
		}
	}
	return 0;
}
