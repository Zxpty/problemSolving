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
	int a, b, c, d; cin >> a >> b >> c >> d;
	int ans = -1e9;
	for(int i = -100; i <= 100; i++){
		for(int j = -100; j <= 100; j++){
			if((i >= a && i <= b) && (j >= c && j <= d)){
				ans = max(ans, i - j);
			}
		}
	}
	cout << ans;
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
