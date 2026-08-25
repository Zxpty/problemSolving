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
	vector<int> temperatura(n + 1);
	vector<vector<int>> adj(n + 1);
	int raiz = -1;
	int sum_total = 0;
	for(int u = 1; u <= n; u++){
		int v, t; cin >> v >> t;
		sum_total += t;
		if(v == 0){
			temperatura[u] = t;
			raiz = u;
			continue;
		}
		temperatura[u] = t;
		adj[v].push_back(u);
	}


	if(sum_total % 3 != 0){
		cout << -1 << "\n";
		return;
	}
	
	int target = sum_total / 3;

	vector<int> ans;
	function<int(int)> dfs = [&](int node){
		int sum_init = temperatura[node];
		for(int v : adj[node]){
			sum_init += dfs(v);
		}
		if(sum_init == target && node != raiz){
			ans.push_back(node);
			return 0;
		}
		return sum_init;
	};

	dfs(raiz);
	if(int(ans.size()) < 2){
		cout << -1 << '\n';
		return;
	}

	cout << ans[0] << " " << ans[1] << '\n';

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
