#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
#include <functional>
#include <optional>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define sz(a) ((int)(a).size())
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.ff, ", ", x.ss, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.ff, ' ', x.ss); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}


typedef int64_t i64;
const long long MX = 1e9+7;

void GA(){
	int n; read(n);
	vector<vector<int>> r(n, vector<int>(6));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			cin>>r[i][j];
		}
	}


	vector<vector<int>> adj(2 * n + 1);
	set<pair<int, int>> st;
	map<array<int, 3>, int> mp;

	auto check = [&](){
		vector<bool> vis(2 * n + 1);
		bool ok = 0;
		function<void(int, int)> dfs =[&](int node, int parent){
			vis[node] = 1;
			for(auto x : adj[node]){
				if(x == parent) continue;
				if(vis[x]) ok = 1;
				else dfs(x, node);
			}
		};
		for(int i = 1; i <= 2 * n; i++){
			if(!vis[i]){
				dfs(i, -1);
			}
		}
		return ok;
	};

	int node = 1;
	for(int i = 0; i < n; i++){
		array<int, 3> a = {r[i][0], r[i][1], r[i][2]};
		if(!mp.count(a)) mp[a] = node++;
		array<int, 3> b = {r[i][3], r[i][4], r[i][5]};
		if(!mp.count(b)) mp[b] = node++;

		int first_ID = mp[a];
		int second_ID = mp[b];
		if(first_ID > second_ID) swap(first_ID, second_ID);
		if(first_ID == second_ID)continue;
		if(!st.count({first_ID, second_ID})){
			adj[first_ID].push_back(second_ID);
			adj[second_ID].push_back(first_ID);
			st.insert({first_ID, second_ID});
		}
	} 
	if(check()) cout << "True closed chains" << '\n';
	else cout << "No true closed chains" << '\n';
	for(int i = 0; i <= 2 * n; i++) adj[i].clear();
	st.clear();
	map<array<int, 2>, int> mp2;
	node = 1;
	for(int i = 0; i < n; i++){
		array<int, 2> a = {r[i][0], r[i][1]};
		if(!mp2.count(a)) mp2[a] = node++;
		array<int, 2> b = {r[i][3], r[i][4]};
		if(!mp2.count(b)) mp2[b] = node++;
		int first_ID = mp2[a];
		int second_ID = mp2[b];
		if(first_ID > second_ID) swap(first_ID, second_ID);
		if(first_ID == second_ID) continue;
		if(!st.count({first_ID, second_ID})){
			adj[first_ID].push_back(second_ID);
			adj[second_ID].push_back(first_ID);
			st.insert({first_ID, second_ID});
		}
	}
	if(check()) cout << "Floor closed chains" << '\n';
	else cout << "No floor closed chains" << '\n';
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
