#include <algorithm>
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 100005;

long long dp[MX];

void UWU(){
	memset(dp, -1, sizeof(dp));
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}


	function<long long(int)> dfs = [&](int node){
		if(dp[node] != -1) return dp[node];
		long long ans = 0;
		for(int v : adj[node]){
			ans = max(ans, dfs(v) + 1);
		}
		// dfs(v) + 1 basicamnet es obligar a calcular el path de ese nodo y si lo encuentra puesta ya retoanr el dp node pues no
		// y sumarle uno para llegar a mi nodo
		return dp[node] = ans;
	};
	for(int i = 1; i <= n; i++){
		dfs(i);
	}
	long long mx = 0;
	for(int i = 1; i <= n; i++){
		mx = max(mx, dp[i]);
	}
	cout << mx;
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
