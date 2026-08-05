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
	vector<long long> r(n);
	for(auto& x : r) cin >> x;

	long long mn = 2e18;
	long long mn_id = -1;
	map<long long, int> mp;
	for(int i = 0; i < n; i++){
		if(r[i] > 0 && r[i] < mn){
			mn = r[i];
			mn_id = i;
		}
	}
	if(mn_id == -1){
		cout << -1 << '\n';
		return;
	}
	multiset<long long> nega;
	multiset<long long> pos;

	for(int i = 0; i < n; i++){
		if(i == mn_id) continue;
		if(r[i] > 0) pos.insert(r[i]);
		else nega.insert(r[i]);
	}
	vector<long long> ans(n);
	ans[0] = mn;
	long long curr = mn;
	for(int i = 1 ; i < n; i++){
		long long need = 1 - curr;
		auto it = nega.lower_bound(need);
		if(it != nega.end()){
			long long val = *it;
			curr += val;
			ans[i] = curr;
			nega.erase(it);
		}else if(!pos.empty()){
			auto it = pos.begin();
			long long val = *it;
			curr += val;
			ans[i] = curr;
			pos.erase(it);
		}else{
			cout << "-1" << '\n';
			return;
		}
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
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
