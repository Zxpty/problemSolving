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
	int a, b; cin >> a >> b;
	int c = a + b;
	if(c >= 15 && b >= 8) cout << "1";
	else if(c >= 10 && b >= 3) cout << "2";
	else if(c >= 3) cout << "3";
	else cout << "4";
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
