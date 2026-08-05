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
	int n, k; cin >> n >> k;
	vector<int> freq(32);
	for(int i = 0; i < n; i++){
		int num; cin >> num;
		for(int bit = 0; bit < 32; bit++){
			if((num & (1 << bit))) freq[bit]++;
		}
	}
	for(int i = 30; i >= 0; i--){
		int need = n - freq[i];
		if(k > 0 && need <= k){
			freq[i] += need;
			k -= need;
		}
	}

	/*for(int i = 0; i < 32; i++){
		cout << "pos: " << i  << " "<< freq[i] << endl;
	}*/

	long long ans = 0;
	for(int i = 0; i < 32; i++){
		if(freq[i] == n){
			ans += (1LL << i);
		}
	}
	cout << ans << '\n';

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
