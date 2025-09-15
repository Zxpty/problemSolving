#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("haybales.in", "r", stdin);
	int n, q; cin>> n >> q;
	vector<int> r(n);
	for(int& x : r) cin>>x;
	sort(r.begin(), r.end());
	freopen("haybales.out", "w", stdout);
	while(q--){
		int a, b; cin >> a >> b;
		auto it1 = lower_bound(r.begin(), r.end(), a);
		auto it2 = upper_bound(r.begin(), r.end(), b);
		int dis1 = distance(r.begin(), it1);
		int dis2 = distance(r.begin(), it2);
		if (it1 == r.end()) dis1 = n;
		if (it2 == r.end()) dis2 = n;
		cout << dis2 - dis1 << "\n";
	}
	return 0;
}

