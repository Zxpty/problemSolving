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
	vector<int> r(n);
	for(int& x : r) cin >> x;
	int mn = min(n, k);
	for(int i = mn; i < n; i++) cout << r[i] << " ";
	for(int i = 0; i < mn; i++) cout << 0 << " ";
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
