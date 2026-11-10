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
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int l; cin >> l;
		vector<int> p(l);
		for(int j = 0; j < l; j++){
			cin >> p[j];
		}
		for(int j = 1; j < l; j++){
			adj[p[j]].push_back(p[j - 1]);
			adj[p[j - 1]].push_back(p[j]);
		}
	}

	vector<int> vis(n + 1);
	map<int, int> mp;
	map<int, int> key;
	int start = 1;
	int cn = 0;
	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		mp[node] = start;
		cn++;
		for(int v : adj[node]){
			if(!vis[v]){
				dfs(v);
			}
		}
	};

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
			key[start] = cn;
			start++;
			cn = 0;
		}
	}

	vector<int> ans(n + 1);
	for(int i = 1; i <= n; i++){
		ans[i] = key[mp[i]];
		cout << ans[i] << " ";
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
