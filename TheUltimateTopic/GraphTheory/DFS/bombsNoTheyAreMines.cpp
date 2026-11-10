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
	int r, c;
	vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	while(cin >> r >> c){
		if(r == 0 && c == 0) break;
		vector<vector<char>> adj(r, vector<char>(c, '.'));
		int n; cin >> n;
		for(int i = 0; i <= n; i++){
			int row; cin >> row;
			int cn; cin >> cn;
			for(int j = 0; j < cn; j++){
				int col; cin >> col;
				adj[row][col] = '#';
			}
		}
		int r_start, c_start; cin >> r_start >> c_start;
		int r_dest, c_dest; cin >> r_dest >> c_dest;
		vector<vector<int>> dist(r, vector<int>(c, -1));
		queue<pair<int, int>> q;
		q.push({r_start, c_start});
		dist[r_start][c_start] = 0;
		while(!q.empty()){
			auto [x, y] = q.front(); q.pop();
			for(auto [rx, ry] : delta){
				int nx = x + rx;
				int ny = y + ry;
				if(nx >= r || ny >= c || nx < 0 || ny < 0) continue;
				if(adj[nx][ny] == '#') continue;
				if(dist[nx][ny] == -1){
					dist[nx][ny] = dist[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
		cout << dist[r_dest][c_dest] << '\n';
	}
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
