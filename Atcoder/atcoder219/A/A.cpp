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
	if(n >= 0 && n < 40){
		cout << 40 - n;
		return;
	}
	if(n >= 40 && n < 70){
		cout << 70 - n;
		return;
	}
	if(n >= 70 && n < 90){
		cout << 90 - n;
		return;
	}
	cout << "expert";
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
