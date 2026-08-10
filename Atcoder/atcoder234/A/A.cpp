#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

long long f(int x){
	return 1LL * (x * x) + (2 * x) + 3;
}

void UWU(){
	int t; cin >> t;
	cout << f(f(f(t) + t) + f(f(t)));
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
