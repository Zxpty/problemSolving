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
	int n = 4;
	vector<int> r(n);
	for(int& x : r) cin >> x;
	for(int mask = 0; mask < (1 << n); mask++){
		int first = 0;
		int second = 0;
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)) first += r[i];
			else second += r[i];
		}
		if(first == second){
			cout << "YES";
			return;
		}
	}
	cout << "NO";
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
