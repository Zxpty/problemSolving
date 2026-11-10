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
	for(int i = 0; i < n; i++) cin >> r[i];

	sort(r.begin(), r.end());

	long long sum = r[0];
	long long ans = r[0];
	for(int i = 1; i < n; i++){
		sum += r[i];
		ans |= r[i];
		ans |= sum;
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
