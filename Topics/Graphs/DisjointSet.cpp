#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
/*
 * if we wan to check if 1 & 5 in the same component
  -> maybe we can use dfs-bfs but it take O(n + m)
  and with disjoint set we can in constant time
  * Applied in dynamic graphs: when graphs change its configurations
  
  Disjoint:
  * find the parent
  * union:
   -> Rank
   -> Size
*/

class DisjointSet {
	vector<int> rank, parent;
	public:
	DisjointSet(int n){
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		for(int i = 0; i <= n; i++) parent[i] = i;
	}

	int findUltimateParent(int node){
		if(node == parent[node]) return node;
		return parent[node] = findUltimateParent(parent[node]);
	}
	
	void uninByRank(int u, int v){
		int ulp_u = findUltimateParent(u);
		int ulp_v = findUltimateParent(v);
		if(ulp_u == ulp_v) return;
		if(rank[ulp_u] < rank[ulp_v]){
			parent[ulp_u] = ulp_v;
		}else if(rank[ulp_v] < rank[ulp_u]){
			parent[ulp_v] = ulp_u;
		}else{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}

};


int main() {
	cpu();
	DisjointSet ds(7);
	ds.uninByRank(1, 2);
	ds.uninByRank(2, 3);
	ds.uninByRank(4, 5);
	ds.uninByRank(6, 7);
	ds.uninByRank(5, 6);
	// if 3 and 7 same component or not
	if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
		cout << "Same\n";
	}else{
		cout << "Not same\n";
	}
	ds.uninByRank(3, 7);

	if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
		cout << "Same\n";
	}else{
		cout << "Not same\n";
	}
	return 0;
}

