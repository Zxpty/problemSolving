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
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> arr(n + 1);
	vector<int> vis(n + 1);
	function<void(int, int)> dfs = [&](int node, int color){
		arr[node] = color;
		vis[node] = 1;
		int new_color = (color == 1 ? 0 : 1);
		for(int v : adj[node]){
			if(!vis[v]){
				dfs(v, new_color);
			}
		}
	};
	dfs(1, 1);
	long long zero = 0, one = 0;
	for(int i = 1; i <=n; i++){
		//cout << arr[i] << " ";
		if(arr[i] == 1) one++;
		else zero++;
	}
	long long comb = zero * one;
	long long ans = comb - (n - 1);
	cout << ans << "\n";
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
