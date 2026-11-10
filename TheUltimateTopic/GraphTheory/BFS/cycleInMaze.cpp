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
	int n, m, k; cin >> n >> m >> k;
	if(k % 2){
		cout << "IMPOSSIBLE";
		return;
	}
	vector<string> s(n);
	for(auto& x : s) cin >> x;
	int x = -1, y = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'X'){
				x = i;
				y = j;
				break;
			}
		}
	}


	vector<pair<int, int>> delta = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
	map<pair<int, int>, char> mp = {{{1, 0}, 'D'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}};

	auto check = [&](int r, int c){
		return r >= 0 && r < n && c >= 0 && c < m && s[r][c] != '*';
	};

	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<array<int, 2>> q;
	q.push({x, y});
	dist[x][y] = 0;

	while(!q.empty()){
		auto [r, c] = q.front(); q.pop();
		for(auto [rx, ry] : delta){
			int nx = r + rx;
			int ny = c + ry;
			if(check(nx, ny)){
				if(dist[nx][ny] == -1){
					q.push({nx, ny});
					dist[nx][ny] = dist[r][c] + 1;
				}
			}
		}
	}

	string res;
	while(k--){
		bool ok = 0;
		for(auto [rx, ry] : delta){
			int nx = x + rx;
			int ny = y + ry;
			if(check(nx, ny) && dist[nx][ny] <= k){
				res.push_back(mp[{rx, ry}]);
				ok = 1;
				x = nx;
				y = ny;
				break;
			}
		}
		if(!ok){
			cout << "IMPOSSIBLE";
			return;
		}
	}
	cout << res;

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
