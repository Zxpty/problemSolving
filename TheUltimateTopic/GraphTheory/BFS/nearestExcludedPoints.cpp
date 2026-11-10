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
	int n; cin >> n;
	vector<pair<int, int>> cords(n);
	map<pair<int, int>, int> mp;
	for(int i = 0; i < n; i++){
		cin >> cords[i].first >> cords[i].second;
		mp[cords[i]] = 1;
	}

	map<pair<int, int>, int> vis;
	map<pair<int, int>, pair<int, int>> ans;
	vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++){
		int x = cords[i].first;
		int y = cords[i].second;
		for(auto [rx, ry] : delta){
			int nx = x + rx;
			int ny = y + ry;
			if(!mp.count({nx, ny}) && !vis.count({nx, ny})){
				q.push({nx ,ny});
				vis[{nx, ny}] = 1;
				ans[{nx, ny}] = {nx, ny};
			}
		}
	}

	while(!q.empty()){
		auto [x, y] = q.front(); q.pop();
		for(auto [rx, ry] : delta){
			int nx = x + rx;
			int ny = y + ry;
			if(mp.count({nx, ny}) && !vis.count({nx, ny})){
				vis[{nx, ny}] = 1;
				ans[{nx, ny}] = ans[{x, y}];
				q.push({nx, ny});
			}
		}
	}

	for(int i = 0; i < n; i++){
		cout << ans[cords[i]].first << " " << ans[cords[i]].second << "\n";
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
