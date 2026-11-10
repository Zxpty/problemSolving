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
	string a, b;
	map<char, int> mp = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}};

	vector<pair<int, int>> delta = {{-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
	auto valid = [&](int r, int c){
		return r >= 1 && r <= 8 && c >= 1 && c <= 8;
	};

	while(cin >> a >> b){
		int x = mp[a[0]];
		int y = a[1] - '0';
		int x2 = mp[b[0]];
		int y2 = b[1] - '0';
		map<pair<int, int>, int> dist;
		queue<pair<int, int>> q;
		q.push({x, y});
		dist[{x, y}] = 0;
		while(!q.empty()){
			auto [r, c] = q.front(); q.pop();
			if(r == x2 && c == y2){
				int distance = dist[{r, c}];
				cout << "To get from " << a << " " << "to" << " " << b << " " << "takes " << distance << " " << "knight moves." << endl;
				break;
			}
			for(auto [rx, ry]: delta){
				int nx = r + rx;
				int ny = c + ry;
				if(valid(nx, ny)){
					if(dist.count({nx, ny}) == 0){
						dist[{nx, ny}] = dist[{r, c}] + 1;
						q.push({nx, ny});
					}
				}
			}
		}
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
