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
	vector<int> r(6);
	for(int i = 1; i <= 5; i++){
		cin >> r[i];
	}
	for(int i = 1; i <= 5; i++){
		if(r[i] == 0){
			cout << i;
			return;
		}
	}
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
