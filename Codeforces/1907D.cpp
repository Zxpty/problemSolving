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
	int n; cin >> n;
	vector<pair<int, int>> seg(n);
	int mx = 0;
	for(int i = 0; i < n; i++){
		cin >> seg[i].first >> seg[i].second;
		mx = max({seg[i].first, seg[i].second, mx});
	}


	auto check = [&](int k){
		int left = 0, right = 0;
		for(int i = 0; i < n; i++){
			left = max(left - k, seg[i].first);
			right = min(right + k, seg[i].second);
			if(left > right) return false;
		}
		return true;
	};

	int left = 0;
	int right = mx;
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(check(mid)){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	cout << left << '\n';

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
