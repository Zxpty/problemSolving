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
	int y; cin >> y;
	if(y % 4 == 0) cout << y + 2;
	if(y % 4 == 1) cout << y + 1;
	if(y % 4 == 2) cout << y;
	if(y % 4 == 3) cout << y + 3;
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
