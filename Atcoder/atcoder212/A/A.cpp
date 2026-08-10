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
	int a, b; cin >> a >> b;
	if(a > 0 && b == 0){
		cout << "Gold";
	}else if(a == 0 && b > 0){
		cout << "Silver";
	}else{
		cout << "Alloy";
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
