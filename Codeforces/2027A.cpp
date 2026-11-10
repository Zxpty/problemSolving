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
	int first = 0, second = 0;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		first = max(x, first);
		second = max(y, second);
	}
	cout << 2 * (first + second) << '\n';
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
