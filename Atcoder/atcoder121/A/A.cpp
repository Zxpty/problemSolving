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
	int H, W; cin >> H >> W;
	int h, w; cin >> h >> w;
	int total = H * W;
	int first = h * W;
	int second = (H - h) * w;
	total -= first;
	total -= second;
	cout << total;

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
