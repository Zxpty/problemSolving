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
	for(long long& x : r) cin >> x;
	long long one = 0, ten = 0, hundred = 0;
	for(int i = 0; i < n; i++){
		long long first = 1000 * ((r[i] + 999) / 1000);
		long long top = first - r[i];
		hundred += (top / 100);
		top %= 100;
		ten += (top / 10);
		top %= 10;
		one += top;
	}
	cout << one << " " << ten << " " << hundred;
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
