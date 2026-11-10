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
	int n, k; cin >> n >> k;
	vector<long long> r(n); 
	for(long long& x : r) cin >> x;

	long long mn = *min_element(r.begin(), r.end());
	int left = mn;
	int right = mn + k;


	auto check = [&](int h){
		int pos = -1;
		for(int i = n - 1; i >= 0; i--){
			if(r[i] < h){
				pos = i;
				break;
			}
		}
		if(pos == -1) return true;

		int start = 0;
		for(int i = pos; i >= 0; i--){
			if(start >= k + 1){
				if(r[i] < h){
					return false;
				}
			}else{
				if(r[i] + k - start < h){
					return false;
				}
			}
			start++;
		}
		return true;
	};
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(check(mid)){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	cout << right;
	//cout << left << " " << right;
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
