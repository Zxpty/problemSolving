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
	vector<int> r(n + 1);
	map<int, int> mp;
	for(int i = 1; i <=n; i++){
		cin >> r[i];
		mp[i] = r[i];
	}

	for(int i = 1; i <= n; i++){
		if(mp[mp[mp[i]]] == i){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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
