#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

void UWU(){
	int n, m; cin >> n >> m;
	vector<string> r(n);
	for(auto& x : r) cin >> x;
	int good = 0, bad = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(r[i][j] == 'G') good++;
			else if(r[i][j] == 'B') bad++;
		}
	}
	if(not bad && not good){
		cout << "Yes\n";
		return;
	}

	if(bad && not good){
		cout << "Yes\n";
		return;
	}

	vector<vector<int>> vis(n, vector<int>(m));
	vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	auto check = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m;
	};

	vector<string> grid = r;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(r[i][j] == 'B'){
				for(auto [rx, ry]: delta){
					int nx = i + rx;
					int ny = j + ry;
					if(check(nx, ny) && (r[nx][ny] == '.' || r[nx][ny] == 'G')){
						vis[nx][ny] = 1;
						grid[nx][ny] = '#';
					}
				}
			}
		}
	}
	/*for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl; */

	vector<vector<int>> temp = vis;
	function<bool(int, int)> dfs = [&](int x, int y){
		for(auto [rx, ry] : delta){
			int nx = x + rx;
			int ny = y + ry;
			if(!check(nx, ny)) continue;
			if(grid[nx][ny] == '#' || grid[nx][ny] == 'B') continue;
			if(nx == n - 1 && ny == m - 1) return true;
			if(!vis[nx][ny]){
				vis[nx][ny] = 1;
				if(dfs(nx, ny)) return true;
			}
		}
		return false;
	};
	/*for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << vis[i][j];
		}
		cout << endl;
	}
	cout << endl; */
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 'G'){
				if(dfs(i, j)){
					good--;
				}
				vis = temp;
			}
		}
	}
	if(good == 0){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
