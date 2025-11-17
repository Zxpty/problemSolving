#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(0);cin.tie(0);
using namespace std;


void Ga(){
    int n; cin >> n;
    int m = n - 1;
    vector<int> dp(n + 1, 1);
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= m; i++){
        int u, v = i;
        adj[u].push_back(v);
    }
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i++){
        int wx; cin >> wx;
        w[i] = wx;
    }
    function<void(int)> dfs = [&](int node){
        for(auto v : adj[node]){
            if(w[node] < w[v]){
                dp[v] += dp[node] + 1;
            }
        }
    };
    dfs(1);
    for(int x : dp) cout << x << " ";
    
}
int main() {
    cpu();
    int t = 1;
    //cin >> t;
    while (t--) {
        Ga();
    }
    return 0;
}