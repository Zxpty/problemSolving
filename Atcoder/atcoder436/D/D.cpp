#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const long long INF = 1e18;

void UWU(){
	int h, w; cin >> h >> w;
	vector<string> r(h);
	vector<vector<pair<int, int>>> mp(26);
	for(int i = 0; i < h; i++){
		cin >> r[i];
		for(int j = 0; j < w; j++){
			char val = r[i][j];
			if(islower(val)){
				mp[val - 'a'].push_back({i, j});
			}
		}
	}

	vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	vector<vector<long long>> dis(h, vector<long long>(w, INF));

	auto valid = [&](int x, int y){
		return x >= 0 && x < h && y >= 0 && y < w && r[x][y] != '#' && dis[x][y] == INF; 
	};

	vector<int> seen(26);
	queue<pair<int, int>> q;
	q.push({0, 0});
	dis[0][0] = 0;

	while(!q.empty()){
		auto [x, y] = q.front(); q.pop();

		for(auto [rx, ry] : delta){
			int nx = rx + x;
			int ny = ry + y;
			if(valid(nx, ny)){
				dis[nx][ny] = dis[x][y] + 1;
				q.push({nx, ny});
			}
		}
		char val = r[x][y];
		if(islower(val)){
			int id = val - 'a';
			if(seen[id]) continue;
			seen[id] = 1;
			for(auto [rx, ry] : mp[id]){
				if(dis[rx][ry] == INF){
					dis[rx][ry] = dis[x][y] + 1;
					q.push({rx, ry});
				}
			}
		}
	}
	long long ans = dis[h - 1][w - 1];
	if(ans == INF) cout << "-1";
	else cout << ans;
	
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
