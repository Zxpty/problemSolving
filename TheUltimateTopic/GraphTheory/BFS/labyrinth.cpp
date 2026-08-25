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
	
	vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
	map<pair<int, int>, char> mp = {{{1, 0}, 'D'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}};

	queue<pair<int, int>> q;
	vector<vector<int>> dist(n, vector<int>(m, -1));
	vector<vector<pair<int, int>>> padre(n, vector<pair<int, int>>(m, {-1, -1}));
	map<pair<int, int>, char> val;

	auto check = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1 && r[x][y] != '#';
	};
	pair<int, int> inicio = {-1, -1};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(r[i][j] == 'A'){
				inicio = {i, j};
				break;
			}
		}
	}
	dist[inicio.first][inicio.second] = 0;
	padre[inicio.first][inicio.second] = {-1, -1};
	q.push({inicio.first, inicio.second});

	while(!q.empty()){
		auto[x, y] = q.front();
		q.pop();
		if(r[x][y] == 'B'){
			cout << "YES\n";
			cout << dist[x][y] << "\n";
			vector<char> ans;
			pair<int, int> actual = {x, y};
			while(actual != inicio){
				char key = val[actual];
				ans.push_back(key);
				actual = padre[actual.first][actual.second];
			}
			reverse(ans.begin(), ans.end());
			for(auto c : ans){
				cout << c;
			}
			return;
		}
		for(auto [rx, ry] : delta){
			int nx = rx + x;
			int ny = ry + y;
			char move = mp[{rx, ry}];
			if(check(nx, ny)){
				dist[nx][ny] = dist[x][y] + 1;
				padre[nx][ny] = {x, y};
				val[{nx, ny}] = move;
				q.push({nx, ny});
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
		UWU();
	}
	return 0;
}
