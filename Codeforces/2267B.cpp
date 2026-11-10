#include <algorithm>
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
	vector<int> r(n);
	for(int& x : r) cin >> x;
	map<int, int> mp;
	for(int x : r) mp[x]++;

	int mx = *max_element(r.begin(), r.end());

	vector<int> ans;
	for(int i = 0; i < mp[mx]; i++){
		ans.push_back(mx);
	}

	mp.erase(mx);
	while(true){
		vector<int> temp;
		for(auto& [val, freq] : mp){
			if(freq == 0) continue;
			temp.push_back(val);
			freq--;
		}
		if(temp.empty()) break;
		reverse(temp.begin(), temp.end());
		for(int x : temp) ans.push_back(x);
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
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
