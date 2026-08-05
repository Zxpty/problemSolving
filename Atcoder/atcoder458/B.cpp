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
	int h, w; cin >> h >> w;
	int ans[h][w];

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			ans[i][j] = 0;
			if(i - 1 >= 0) ans[i][j]++;
			if(i + 1 < h) ans[i][j]++;
			if(j - 1 >= 0) ans[i][j]++;
			if(j + 1 < w) ans[i][j]++;
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << ans[i][j] << " ";
		}
		cout << '\n';
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
