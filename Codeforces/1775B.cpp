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
	vector<vector<int>> r;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int m; cin >> m;
		vector<int> p(m);
		for(int& x : p) cin >> x;
		for(int x : p) mp[x]++;
		r.push_back(p);
	}

	for(auto e : r){
		int ok = 1;
		for(int x : e){
			if(mp[x] <= 1){
				ok = 0;
				break;
			}
		}
		if(ok){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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
