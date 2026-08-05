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
	long long a, b, x; cin >> a >> b >> x;
	long long first = a ^ 1;
	long long second  = b ^ 1;
	long long ans = abs(first - second);
	cout << first << " " << second << '\n';
	cout << ans << endl;
	
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
