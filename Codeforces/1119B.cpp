#include <algorithm>
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
	int n, h; cin >> n >> h;
	vector<long long> r(n);
	for(long long& x : r) cin >> x;
	long long ans = 1;
	for(int i = 1; i < n; i++){
		sort(r.begin(), r. begin() + i + 1);
		long long sum = 0;
		for(int j = i; j >= 0; j -= 2){
			sum += r[j];
		}
		if(sum <= h){
			ans = max(ans, 1LL * (i + 1));
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
