#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;

void solve(){
	int n; read(n);
	vector<vector<int>> adj(n+1);
	vector<int> root;
	for(int i=0;i<n;i++){
		int parent; cin>>parent;
		if(parent==-1){root.push_back(i+1);continue;}
		adj[parent].push_back(i+1);
	}

	vector<bool> vis(n+1,false);
	queue<pair<int,int>> q;
	for(int x : root){
		q.push({x,1});
		vis[x] = 1;
	}
	int ans = 0;
	while(!q.empty()){
		auto[nodo,distancia] = q.front();q.pop();
		ans = max(ans,distancia);
		dbg(ans);
		for(int v : adj[nodo]){
			if(vis[v])continue;
			q.push({v,distancia+1});
			vis[v] = 1;
		}
	}
	cout<<ans<<'\n';

	
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
