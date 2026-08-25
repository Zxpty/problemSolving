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
	vector<int> color(n + 1);
	int red = 0, blue = 0;
	for(int i = 1; i <=n; i++){
		cin >> color[i];
		if(color[i] == 1) red++;
		else if(color[i] == 2) blue++;
	}

	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;
	function<pair<int, int>(int, int)> dfs = [&](int node, int parent){
		pair<int, int> sum_init = {0, 0};
		if(color[node] == 1) sum_init.first++;
		else if(color[node] == 2) sum_init.second++;
		for(int v : adj[node]){
			if(v != parent){
				pair<int,int> reporte_son = dfs(v, node);
				sum_init.first += reporte_son.first;
				sum_init.second += reporte_son.second;
			}
		}
		if((sum_init.first == red && sum_init.second == 0) || (sum_init.first == 0 && sum_init.second == blue)){
			ans++;
		}
		return sum_init;
	};
	dfs(1, 0);
	cout << ans << '\n';


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
