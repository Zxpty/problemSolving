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
	vector<int> a(7 * n);
	for(int i = 0; i < 7 * n; i++) cin >> a[i];

	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < 7; j++) sum += a[7 * i + j];
		cout << sum << " ";
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
