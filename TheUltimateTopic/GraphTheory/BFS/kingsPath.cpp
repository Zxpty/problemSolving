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
	int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
	set<pair<int, int>> permitidos;
	queue<pair<int, int>> q;
	map<pair<int, int>, int> dist;
	int m; cin >> m;
	for(int i = 0; i < m; i++){
		int row, from, to; cin >> row >> from >> to;
		for(int j = from; j <= to; j++){
			permitidos.insert({row, j});
		}
	}

	vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {0, -1}, {-1, 0}};

	q.push({x0, y0});
	dist[{x0, y0}] = 0;

	while(!q.empty()){
		auto [x, y] = q.front(); q.pop();
		//cout << "----------\n";
		//cout << x << " " << y;
		//cout << "----------\n";
		if(x == x1 && y == y1){
			cout << dist[{x, y}];
			return;
		}

		for(auto [rx, ry] : delta){
			int nx = x + rx;
			int ny = y + ry;
			if(permitidos.count({nx, ny})){
				if(dist.count({nx, ny}) == 0){
					dist[{nx, ny}] = dist[{x, y}] + 1;
					q.push({nx, ny});
				}
			}
		}
	}
	cout << -1;
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
