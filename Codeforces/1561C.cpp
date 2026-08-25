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
	vector<vector<int>> a(n);
	vector<pair<int, int>> info(n);

	int mx = 0;
	for(int i = 0; i < n; i++){
		int m; cin >> m;
		int need = 0;
		for(int j = 0; j < m; j++){
			int monster; cin >> monster;
			a[i].push_back(monster);
			need = max(need, monster - j + 1);
			mx = max(mx, monster);
		}
		info[i] = {need, m};
	}

	sort(info.begin(), info.end());

	auto check = [&](int power){
		for(auto [need, gain] : info){
			if(power < need){
				return false;
			}
			power += gain;
		}
		return true;
	};

	int left = 1, right = mx + n + 1;
	while(left <= right){
		int mid = (left + (right - left) / 2);
		if(check(mid)){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	cout << left << endl;


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
