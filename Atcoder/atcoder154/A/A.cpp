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
	string a, b; cin >> a >> b;
	int f1, f2; cin >> f1 >> f2;
	map<string, int> mp;
	mp[a] = f1;
	mp[b] = f2;
	string minus; cin >> minus;
	mp[minus]--;
	cout << mp[a] << " " << mp[b];
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
