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
	int n = 5;
	vector<int> r(n);
	for(int& x : r) cin >> x;
	int k; cin >> k;
	for(int i = 0; i < n; i++){
		int val = r[i];
		for(int j = 0; j < i; j++){
			if(val - r[j] > k){
				cout << ":(";
				return;
			}
		}
	}
	cout << "Yay!";
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
