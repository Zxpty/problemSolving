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
	int n, k, t; cin >> n >> k >> t;
	vector<int> r(n);
	for(int& x : r) cin >> x;
	sort(r.begin(), r.end());

	vector<pair<int, int>> p;
	for(int i = 0; i < n; i++){
		int start = r[i];
		if(start > t) break;
		int end = r[i] + k;
		p.push_back({start, end});
	}
	if(p.empty()){
		cout << (t  + k - 1) / k;
		return;
	}
	long long ans = (p[0].first + k - 1) / k;
	long long curr_end = p[0].second;
	for(int i = 1; i < int(p.size()); i++){
		long long ini_now = p[i].first;
		long long dis = max(0LL, 1LL * ini_now - curr_end);
		long long calc = (dis + k - 1) / k;
		ans += calc;
		curr_end = max(curr_end, (long long) p[i].second);
	}
	if(curr_end < t){
		long long dis = t - curr_end;
		long long calc = (dis + k - 1) / k;
		ans += max(0LL, calc);
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
