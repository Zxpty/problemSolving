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
	int n, s; cin >> n >> s;
	long long l; cin >> l;
	s--;
	vector<long long> r(n - 1);
	for(auto& x : r) cin >> x;

	vector<long long> left(n);
	for(int i = s - 1; i >= 0; i--){
		left[i] = left[i + 1] + r[i];
	}

	vector<long long> right(n);
	for(int i = s + 1; i < n; i++){
		right[i] = right[i - 1] + r[i - 1];
	}

	int ans = 1;

	for(int i = 0; i <= s; i++){
		for(int j = s; j < n; j++){
			long long lCost = left[i];
			long long rCost = right[j];

			long long first = 2 * lCost + rCost;
			long long second = 2 * rCost + lCost;
			if(first <= l || second <= l){
				ans = max(ans, j - i + 1);
			}
		}
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
