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
	int a, b;
	a = n / 16, b = n % 16;
	if(a <= 9) cout << a;
	else cout << (char) ('A' + a - 10);
	if(b <= 9) cout << b;
	else cout << (char) ('A' + b - 10);
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
