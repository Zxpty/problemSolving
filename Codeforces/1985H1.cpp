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

	vector<vector<int>> id(n, vector<int>(m));
	vector<vector<int>> vis(n, vector<int>(m));
	vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	auto check = [&](int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
	};
	int idx = 0;
	int cn = 0;
	map<int, int> mp;
	function<void(int, int)> dfs = [&](int x, int y){
		vis[x][y] = 1;
		id[x][y] = idx;
		cn++;
		for(auto [rx, ry] : delta){
			int nx = x + rx;
			int ny = y + ry;
			if(check(nx, ny) && r[nx][ny] == '#'){
				dfs(nx, ny);
			}
		}
	};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(check(i, j) && r[i][j] == '#'){
				idx++;
				dfs(i, j);
				mp[idx] = cn;
				cn = 0;
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		set<int> st;
		long long cn = 0;
		for(int j = 0; j < m; j++){
			if(id[i][j] != 0) st.insert(id[i][j]);
			else cn++;

			if(i - 1 >= 0) st.insert(id[i - 1][j]);
			if(i + 1 < n) st.insert(id[i + 1][j]);
		}
		for(auto x : st){
			cn += mp[x];
		}
		ans = max(ans, cn);
	}

	for(int j = 0; j < m; j++){
		set<int> st;
		long long cn = 0;
		for(int i = 0; i < n; i++){
			if(id[i][j] != 0) st.insert(id[i][j]);
			else cn++;

			if(j - 1 >= 0) st.insert(id[i][j - 1]);
			if(j + 1 < m) st.insert(id[i][j + 1]);
		}
		for(auto x : st){
			cn += mp[x];
		}
		ans = max(ans, cn);
	}

	cout << ans << '\n';
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
