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
	int h, w;
	int r, c;
	cin >> h >> w >> r >> c;
	int res = 0;
	if(c != 1) res++;
	if(c != w) res++;
	if(r != 1) res++;
	if(r != h) res++;
	cout << res;
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
