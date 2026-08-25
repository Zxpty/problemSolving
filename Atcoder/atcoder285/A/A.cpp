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
	map<int, set<int>> mp;
	mp[1] = {2, 3};
	mp[2] = {4, 5, 1};
	mp[3] = {1, 6, 7};
	mp[4] = {8, 9, 2};
	mp[5] = {2, 10, 11};
	mp[6] = {12, 13, 3};
	mp[7] = {3, 14, 15};
	mp[8] = {4};
	mp[9] = {4};
	mp[10] = {5};
	mp[11] = {5};
	mp[12] = {6};
	mp[13] = {6};
	mp[14] = {7};
	mp[15] = {7};
	int a, b; cin >> a >> b;
	if(mp[a].count(b)){
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
