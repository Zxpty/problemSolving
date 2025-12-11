#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.first, p.second);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.first, ", ", x.second, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.first, ' ', x.second); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}


const int MX = 1e9;

class DisjointSet {
	vector<int> rank, parent, size;
	public:
	DisjointSet(int n){
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for(int i = 0; i <= n; i++) parent[i] = i;
	}

	int findUltimateParent(int node){
		if(node == parent[node]) return node;
		return parent[node] = findUltimateParent(parent[node]);
	}
	
	bool uninBySize(int u, int v){
		int ulp_u = findUltimateParent(u);
		int ulp_v = findUltimateParent(v);
		if(ulp_u == ulp_v) return 0;
		if(size[ulp_u] < size[ulp_v]){
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}else{
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
		return 1;
	}

};

void ONO(){
	int n; read(n);
	DisjointSet dsu(n);
	vector<pair<int, int>> delEdge;
	for(int i = 0; i < n - 1; i++){
		int u, v; read(u, v);
		if(!dsu.uninBySize(u, v)){
			delEdge.emplace_back(u, v);
		}
	}
	if(delEdge.empty()){
		ps(0);
		return;
	}
	set<int> st;
	for(int i = 1; i <= n; i++){
		st.insert(dsu.findUltimateParent(i));
	}
	vector<pair<int, int>> addEdge;
	auto it = st.begin();
	int node = *it;
	it++;
	while(it != st.end()){
		addEdge.push_back({node, *it});
		it++;
	}
	int m = int(addEdge.size());
	ps(m);
	for(int i = 0; i < m; i++){
		ps(delEdge[i].first, delEdge[i].second, addEdge[i].first, addEdge[i].second);
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
