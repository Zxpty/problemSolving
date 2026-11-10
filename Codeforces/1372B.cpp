#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

int prime_factor(int n){
	if(n < 2) return -1;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return i;
		}
	}
	return n;
}

void UWU(){
	int n; cin >> n;
	if(n % 2 == 0){
		cout << n / 2  << " " << n / 2 << '\n';
		return;
	}

	int first = prime_factor(n);
	cout << n / first << " " << n - (n / first) << "\n";
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
