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
	map<int, set<int>> adj;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		if(u > v) swap(u, v);
		adj[u].insert(v);
	}
	int right = n + 1;
	long long ans = 0;
	for(int i = n; i > 0; i--){
		for(int x : adj[i]){
			right = min(right, x);
		}
		ans += right - i;
	}
	cout << ans << "\n";
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
