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
	int n, a, x, y; cin >> n >> a >> x >> y;
	if(n <= a){
		cout << n * x;
		return;
	 }
	long long ans = a * x;
	long long need = n - a;
	long long other = need * y;
	ans += other;
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
