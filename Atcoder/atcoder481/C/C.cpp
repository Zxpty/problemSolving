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
	map<string, int> mp;
	int start = 1;
	for(int i = 0; i < n; i++){
		string x; cin >> x;
		if(!mp.count(x)){
			mp[x] = start++;
		}
		cout << mp[x] << "\n";
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
