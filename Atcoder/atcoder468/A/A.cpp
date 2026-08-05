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
	for(int &x : r) cin >> x;
	int cn = 0;
	for(int i = 0; i < n - 2; i++){
		if(r[i] < r[i + 1] && r[i + 1] > r[i + 2]) cn++;
	}
	cout << cn;
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
