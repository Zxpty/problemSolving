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
	int n, k; cin >> n >> k;
	vector<int> freq(k + 1);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		freq[x]++;
	}
	map<int, int> mp;
	for(int i = 1; i <= k; i++){
		mp[freq[i]]++;
	}

	vector<int> res;
	for(auto [val, freq] : mp){
		res.push_back(val);
	}
	sort(res.rbegin(), res.rend());
	if(res.size() == 1){
		cout << mp[res[0]] << '\n';
		return;
	}
	int ans = mp[res[0]];
	if(res[0] == res[1] + 1){
		ans += mp[res[1]];
	}
	cout << ans;
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
