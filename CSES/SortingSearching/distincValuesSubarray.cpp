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
	for(int i = 0; i < n; i++) cin >> r[i];
	map<int, int> mp;
	int left = 0, right = 0;
	long long ans = 0;
	while(right < n){
		mp[r[right]]++;
		while(mp[r[right]] > 1){
			mp[r[left]]--;
			if(mp[r[left]] == 0){
				mp.erase(r[left]);
			}
			left++;
		}
		ans += int(mp.size());
		right++;
	}
	cout << ans << "\n";
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
