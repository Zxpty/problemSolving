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
	for(int i = 0; i < n; i++){
		cin >> r[i];
	}
	vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	vector<vector<int>> vis(n, vector<int>(m));
	auto check = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && r[x][y] == '.';
	};


	function<void(int, int)> dfs = [&](int x, int y){
		vis[x][y] = 1;
		for(auto [rx, ry] : delta){
			int new_x = rx + x;
			int new_y = ry + y;
			if(check(new_x, new_y)){
				dfs(new_x, new_y);
			}
		}
	};
	int cn = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(r[i][j] == '#') continue;
			if(!vis[i][j]){
				dfs(i, j);
				cn++;
			}
		}
	}
	cout << cn;
	
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
