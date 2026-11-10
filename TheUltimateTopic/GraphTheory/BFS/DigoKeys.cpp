#include <algorithm>
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
	for(int i = 1; i < n; i++){
		int m; cin >> m;
		vector<int> neightbors;
		for(int j = 0; j < m; j++){
            int x; cin >> x;
            neightbors.push_back(x);
		}
		sort(neightbors.begin(), neightbors.end());
		for(int x : neightbors){
			adj[i].push_back(x);
		}
	}
	vector<int> dist(n + 1, -1);
	vector<int> father(n + 1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	father[1] = -1;
	while(!q.empty()){
		int curr = q.front(); q.pop();
		if(curr == n){
			vector<int> ans;
			int start = father[curr];
			while(start != -1){
				ans.push_back(start);
				start = father[start];
			}
			reverse(ans.begin(), ans.end());
			cout << int(ans.size()) << '\n';
			for(int x : ans){
				cout << x << " ";
			}
			cout << '\n';
			return;
		}
		for(int v : adj[curr]){
			if(dist[v] == -1){
				dist[v] = dist[curr] + 1;
                father[v] = curr;
				q.push(v);
			}
		}
	}
	cout << -1 << '\n';
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
