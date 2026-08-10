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

	int mx_freq = 0, c = 0;
	map<int, int> mp;
	long long sum = 0;
	for(int i = 0; i < n; i++){
		int val = r[i];
		mp[val]++;
		sum += val;
		if(mp[val] > mx_freq){
			mx_freq = mp[val];
			c = val;
		}
	}

	int need = n - mx_freq;
	if(mx_freq <= need + 1){
		cout << sum << '\n';
		return;
	}

	long long calc = sum - (1LL * mx_freq * c);
	long long ans = calc + 1LL * (need + 2) * c;
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
