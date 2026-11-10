#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;


void UWU(){
	long long n, w; cin >> n >> w;
	long long ans = 0;

	vector<long long> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}

	for(int mask = 0; mask < (1 << n); mask++){
		long long first = 0, second = 0;
		for(int i = 0; i < n; i++){
			if((1 << i) & mask){
				first += a[i];
				second += b[i];
			}
		}
		if(second <= w){
			ans = max(ans, first);
		}
	}
	cout << ans << '\n';
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
