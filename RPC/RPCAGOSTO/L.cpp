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
	int target = 2 * n;
	map<int, int> mp;
	n *= 10;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			int x; cin >> x;
			mp[x]++;
		}
	}
	vector<int> ans;
	for(auto [val, freq] : mp){
		if(freq > target){
			ans.push_back(val);
		}
	}
	if(ans.empty()){
		cout << "-1" << endl;
		return;
	}
	sort(ans.begin(), ans.end());
	int m = int(ans.size());
	for(int i = 0; i < m; i++){
		cout << ans[i];
		if(i != m - 1) cout << " ";
	}
	cout << endl;
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
