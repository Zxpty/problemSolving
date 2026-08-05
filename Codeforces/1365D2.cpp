
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

	function<void(int, int)> dfs = [&](int x, int y){
		vis[x][y] = 1;
		for(auto [rx, ry] : delta){
			int nx = x + rx;
			int ny = y + ry;
			if(!check(nx, ny)) continue;
			if(grid[nx][ny] == 'B' || grid[nx][ny] == '#') continue;
			if(!vis[nx][ny]){
				dfs(nx, ny);
			}
		}
	};
	if(grid[n - 1][m - 1] != '#') dfs(n - 1, m - 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 'G' && vis[i][j]){
				good--;
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
