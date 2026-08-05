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
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back({v, i + 1});
		adj[v].push_back({u, i + 1});
	}
	vector<int> color(n);
	int days = 0;
	for(auto x : adj){
		days = max(days, int(x.size()));
	}
	vector<vector<int>> ans(days + 1);
	function<void(int, int, int)> dfs = [&](int node, int father, int fatherColor){
		int now_color = 1;
		int colFather = fatherColor;
		//dbg("NODO", "FATHER", "color", "FatherColor");
		//dbg(node, father, now_color, colFather);
		for(auto [v, id_road] : adj[node]){
			if(v == father) continue;
			if(now_color == colFather) now_color++;
			color[id_road] = now_color;
			dfs(v, node, now_color);
			now_color++;
		}
	};
	dfs(1, -1, 0);
	for(int i = 1; i < n; i++){
		ans[color[i]].push_back(i);
	}
	cout << days << "\n";
	for(int i = 1; i <= days; i++){
		vector<int> vals = ans[i];
		cout << int(vals.size()) << ' ';
		for(int x : vals){
			cout << x << " ";
		}
		cout << '\n';
	}
	//dbg(color);
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
