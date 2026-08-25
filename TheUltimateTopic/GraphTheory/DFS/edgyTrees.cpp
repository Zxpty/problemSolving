#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const long long MOD = 1e9+7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void UWU(){
	long long n, k; cin >> n >> k;
	long long total = binpow(n, k, MOD);
	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v, color; cin >> u >> v >> color;
		if(color == 1) continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n + 1);
	long long cn = 0;

	function<void(int)> dfs = [&](int node){
		vis[node] = 1;
		cn++;
		for(int v : adj[node]){
			if(!vis[v]){
				dfs(v);
			}
		}
	};
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cn = 0;
			dfs(i);
			total -= binpow(cn, k, MOD);
			total = (total % MOD + MOD) % MOD;
		}
	}
	cout << total;
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
