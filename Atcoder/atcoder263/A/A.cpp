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
	int n = 5;
	vector<int> r(n);
	for(int& x : r) cin >> x;

	map<int, int> mp;
	for(int x : r) mp[x]++;
	bool one = 0, two = 0;
	for(auto [val, freq] : mp){
		if(freq == 2) one = 1;
		if(freq == 3) two = 1;
	}
	if(one && two){
		cout << "Yes";
	}else{
		cout << "No";
	}
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
