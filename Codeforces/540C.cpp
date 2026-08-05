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
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	x1--, y1--, x2--, y2--;
	vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

	auto check = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m;
	};
	int cn = 0;
	for(auto [rx, ry] : delta){
		int nx = rx + x2;
		int ny = ry + y2;
		if(check(nx, ny) && r[nx][ny] == '.') cn++;
	}


	if(x1 == x2 && y1 == y2){
		cout << (cn >= 1 ? "YES" : "NO");
		return;
	}

	vector<vector<int>> vis(n, vector<int>(m));
	function<bool(int, int)> dfs = [&](int x, int y){
		for(auto [rx, ry] : delta){
			int nx = rx + x;
			int ny = ry + y;
			if(check(nx, ny)){
				if(nx == x2 && ny == y2) return true;
				if(!vis[nx][ny] && r[nx][ny] == '.'){
					vis[nx][ny] = 1;
					if(dfs(nx, ny)) return true;
				}
			}
		}
		return false;
	};
	vis[x1][y1] = 1;
	bool ok = dfs(x1, y1);
	bool adj = ((abs(x1 - x2)) + (abs(y1 - y2)) == 1);
	if(!ok){
		cout << "NO";
	}else if(r[x2][y2] == 'X'){
		cout << "YES";
	}else{
		if(adj ? (cn >= 1) : (cn >= 2)) cout << "YES";
		else cout << "NO";
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
