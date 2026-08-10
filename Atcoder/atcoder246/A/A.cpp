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
	int x1, x2, x3, y1, y2, y3, xans, yans;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	if(x1 == x2) xans = x3;
	if(x2 == x3) xans = x1;
	if(x3 == x1) xans = x2;

	if(y1 == y2) yans = y3;
	if(y2 == y3) yans = y1;
	if(y3 == y1) yans = y2;
	cout << xans << " " << yans;
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
