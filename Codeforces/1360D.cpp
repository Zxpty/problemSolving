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
	long long n, k; cin >> n >> k;
	long long ans = 1e9;
	for(int i = 1; i * i <= n; i++){
		if(n % i != 0) continue;
		if(i <= k) ans = min(ans, n / i);
		if(n / i <= k) ans = min(ans, n / (n / i));
	}
	cout << ans << '\n';

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
