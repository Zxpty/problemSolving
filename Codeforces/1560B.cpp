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
	int a, b, c;
	cin >> a >> b >> c;
	int end = 2 * abs(a - b);
	if(abs(a - b) == 1 || (max({a, b, c}) > end)){
		cout << -1 << '\n';
		return;
	}
	if(c < 1 + abs(a - b)){
		cout << c + abs(a - b) << '\n';
	}else{
		cout << c - abs(a - b) << '\n';
	}
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
