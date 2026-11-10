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
	map<char, int> mp = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}};
	char a;
	int y;
	char b;
	int y2;

	cin >> a >> y >> b >> y2;
	int x = mp[a];
	int x2 = mp[b];
	map<pair<int, int>, int> dist;
	queue<pair<int, int>> q;
	q.push({x, y});
	dist[{x, y}] = 0;


	vector<pair<int, int>> delta = {{-2, 1}, {2, 1}, {-2, -1}, {2, -1}, {-1, -2}, {1, -2}, {1, 2}, {-1, 2}};

	auto check = [&](int r, int c){
		return r >= 1 && r <= 8 && c >= 1 && c <= 8;
	};

	while(!q.empty()){
		auto [rx, ry] = q.front(); q.pop();
		if(rx == x2 && ry == y2){
			cout << dist[{rx,ry}] << '\n';
			return;
		}
		for(auto [r, c] : delta){
			int nx = rx + r;
			int ny = ry + c;
			if(check(nx, ny)){
				if(dist.count({nx, ny}) == 0){
					dist[{nx, ny}] = dist[{rx, ry}] + 1;
					q.push({nx, ny});
				}
			}
		}
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
