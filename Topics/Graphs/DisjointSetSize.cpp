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
	
	void uninBySize(int u, int v){
		int ulp_u = findUltimateParent(u);
		int ulp_v = findUltimateParent(v);
		if(ulp_u == ulp_v) return;
		if(size[ulp_u] < size[ulp_v]){
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}else{
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
	}

};


int main() {
	cpu();
	DisjointSet ds(7);
	ds.uninBySize(1, 2);
	ds.uninBySize(2, 3);
	ds.uninBySize(4, 5);
	ds.uninBySize(6, 7);
	ds.uninBySize(5, 6);
	// if 3 and 7 same component or not
	if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
		cout << "Same\n";
	}else{
		cout << "Not same\n";
	}
	ds.uninBySize(3, 7);

	if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
		cout << "Same\n";
	}else{
		cout << "Not same\n";
	}
	return 0;
}


