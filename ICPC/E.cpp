#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
void solve()
{
    int n, m; cin >> n >> m;
    map<string, int> ID;
	vector<string> id_name(n);
	vector<int> hr(n);
	vector<vector<int>> adj(n);
	vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int h; cin >> h;
		ID[s] = i;
		id_name[i] = s;
		hr[i] = h;
    }
    for(int i = 0; i < m; i++) {
        string s1, s2; cin >> s1 >> s2;
		int u = ID[s1];
		int v = ID[s2];
		adj[u].push_back(v);
		adj[v].push_back(u);
    }

    function<void(int, int&, int&)> dfs = [&](int node, int& mxH, int& mxID) {
        vis[node] = true;
		if(hr[node] > mxH){
			mxH = hr[node];
			mxID = node;
		}
        for(auto u : adj[node]) {
            if(!vis[u]) {
                dfs(u, mxH, mxID);
            }
        }
    };
	vector<string> ga;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			int mxH = -1, mxID = -1;
			dfs(i, mxH, mxID);
			ga.push_back(id_name[mxID]);
		}
	}
	sort(ga.begin(), ga.end());
	for(auto x : ga) cout << x << '\n';
}
int main()
{
    cpu();
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
        
    return 0;
}

