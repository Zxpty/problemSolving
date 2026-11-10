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

	vector<int> freq(5);
	int odd = 0;
	for(int i = 0; i < n; i++){
		if(r[i] % 2 == 1){
			odd++;
		}else{
			freq[r[i] % 4]++;
		}
	}
	int ans = odd;
	ans = max(ans, freq[2]);
	ans = max(ans, freq[0]);
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
