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
	long long k, x; cin >> k >> x;

	long long left = 1, right = k;
	while(left <= right){
		long long mid = left + (right - left) / 2;
		long long res = mid * (mid + 1) / 2;
		if(res >= x){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	if(left <= k){
		cout << left << "\n";
		return;
	}


	left = 1, right = k - 1;
	long long total_right = (k - 1) * k / 2;
	while(left <= right){
		long long mid = left + (right - left) / 2;
		long long res = k * (k + 1) / 2 + (k - 1) * k / 2 - (k - 1 - mid) * (k - mid) / 2;
		if(res >= x){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	long long ans = k + left;
	cout << min(ans, 2 * k - 1) << "\n";

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
