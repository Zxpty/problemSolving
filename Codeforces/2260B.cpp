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
	long long x, y, k; cin >> x >> y >> k;
	long long d = y - x;

	if(d == 0){
		cout << 0 << '\n';
		return;
	}
	long long cn = min(k, max(0LL, d - x + 1));

	long long res = 0;
	for(long long i = 0; i < cn; i++){
		res += d % (x + i);
	}

	res += (k - cn) * d;
	cout << res << "\n";
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
