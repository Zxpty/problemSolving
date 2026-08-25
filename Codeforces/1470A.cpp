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
	int n, m; cin >> n >> m;

	vector<long long> k(n);
	for(auto& x : k) cin >> x;
	vector<long long> c(m);
	for(auto& x : c) cin >> x;
	
	sort(k.rbegin(), k.rend());

	long long ans = 0;
	int idx = 0;
	for(int i = 0; i < n; i++){
		int j = k[i] - 1;
		if(idx < j){
			ans += c[idx++];
		}else{
			ans += c[j];
		}
	}
	cout << ans << "\n";

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
