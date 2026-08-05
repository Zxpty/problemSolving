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
	vector<int> r(n);
	for(int& x : r) cin >> x;

	for(int i = 0; i < n; i++){
		int left = 1, right = i + 1;
		int ans = 1;
		while(left <= right){
			int mid = (right + left) / 2;
			if(r[i - mid + 1] >= mid){
				ans = mid;
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		cout << ans << " ";
	}
	cout << '\n';
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
