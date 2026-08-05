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
	vector<pair<long long, int>> r(n);
	for(int i = 0; i < n; i++){
		cin >> r[i].first;
		r[i].second = i;
	}
	sort(r.begin(), r.end());
	if(r[0].first != 0){
		cout << "-1" << '\n';
		return;
	}
	vector<long long> ans(n);
	long long last = 0;
	int left = 0;
	while(left < n){
		int right = left;
		while(right < n && r[right].first == r[left].first) right++;
		int cnt = right - left;
		long long val;
		if(right < n){
			long long diff = r[right].first - r[left].first;
			if(diff % cnt != 0){
				cout << -1 << '\n';
				return;
			}
			val = diff / cnt;
			if(val <= last){
				cout << -1 << '\n';
				return;
	 		}
		}else{
			val = (left == 0) ? 1 : last + 1;
		}

		for(int i = left; i < right; i++){
			ans[r[i].second] = val;
		}
		last = val;
		left = right;
	}

	for(int i = 0; i < n; i++){
		cout << ans[i] << " "; 
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
