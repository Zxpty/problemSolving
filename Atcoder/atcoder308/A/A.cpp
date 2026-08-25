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
	int n = 8;
	vector<int> r(8);
	for(int i = 0; i < n; i++){
		cin >> r[i];
	}
	for(int i = 0; i < n; i++){
		if(i + 1 < n){
			if(r[i] > r[i + 1]){
				cout << "No";
				return;
			}
		}
		if(r[i] % 5 != 0){
			cout << "No";
			return;
		}
		if(r[i] < 100 || r[i] > 675){
			cout << "No";
			return;
		}
	}
	cout << "Yes";
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
