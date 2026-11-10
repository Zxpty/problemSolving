#include <bits/stdc++.h>

#ifdef local
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int mx = 1e9+7;
const int inf = -1;

void uwu(){
	int n, m; cin >> n >> m;
	vector<string> grid(n);
	for(auto& s : grid) cin >> s;

	vector<vector<pair<int, int>>> father(n, vector<pair<int, int>>(m, {-1, -1}));
	map<pair<int, int>, char> mp = {{{1, 0}, 'D'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}};
	vector<vector<int>> dist(n, vector<int>(m, inf));
	vector<vector<char>> g(n, vector<char>(m, '.'));
	vector<vector<char>> val(n, vector<char>(m));

	queue<pair<int, int>> q;
	vector<pair<int, int>> players;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 'M'){
				q.push({i, j});
			}
			if(grid[i][j] == 'A'){
				players.push_back({i, j});
			}
			if(grid[i][j] == 'M' || grid[i][j] == 'A'){
				dist[i][j] = 0;
				g[i][j] = grid[i][j];
			}
		}
	}

	for(auto x : players){
		q.push(x);
	}

	vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
	auto check = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
	};

	while(!q.empty()){
		auto [x, y] = q.front(); q.pop();
		for(auto [rx, ry] : delta){
			int nx = x + rx;
			int ny = y + ry;
			if(check(nx, ny)){
				if(dist[nx][ny] == inf){
					dist[nx][ny] = dist[x][y] + 1;
					g[nx][ny] = g[x][y];
					val[nx][ny] = mp[{rx, ry}];
					father[nx][ny] = {x, y};
					q.push({nx, ny});
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 || j == 0 || j == m - 1 || i == n - 1){
				if((grid[i][j] == '.' || grid[i][j] == 'A') && dist[i][j] != inf && g[i][j] == 'A'){
					pair<int, int> start = {i, j};
					string ans;
					while(father[start.first][start.second] != make_pair(-1, -1)){
						ans += val[start.first][start.second];
						start = father[start.first][start.second];
					}
					reverse(ans.begin(), ans.end());
					cout << "YES\n";
					cout << int(ans.size()) << '\n';
					cout << ans;
					return;
				}
			}
		}
	}
	cout << "NO";

}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		uwu();
	}
	return 0;
}
