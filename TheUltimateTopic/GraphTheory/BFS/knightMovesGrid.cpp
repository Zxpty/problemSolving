#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int INF = 1e9+7;

void UWU(){
	int n; cin >> n;
	vector<vector<int>> dist(n, vector<int>(n, INF));

	vector<pair<int, int>> delta = {{-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

	auto check = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < n;
	};

	dist[0][0] = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	while(!q.empty()){
		auto [i, j] = q.front(); q.pop();
		for(auto [rx, ry] : delta){
			int nx = i + rx;
			int ny = j + ry;
			if(check(nx, ny)){
				if(dist[nx][ny] == INF){
					dist[nx][ny] = dist[i][j] + 1;
					q.push({nx, ny});
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dist[i][j] << " ";
		}
		cout << '\n';
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
