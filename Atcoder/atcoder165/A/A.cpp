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
	int k; cin >> k;
	int a, b; cin >> a >> b;
	for(int i = a; i <= b; i++){
		if(i % k == 0){
			cout << "OK";
			return;
		}
	}
	cout << "NG";
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
