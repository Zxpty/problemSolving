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
	int calc = 21 * 60;
	calc += k;
	int hours = calc / 60;
	int minutos = calc % 60;
	if(hours < 10){
		cout << "0";
		cout << hours;
	}else{
		cout << hours;
	}
	cout << ":";
	if(minutos < 10){
		cout << "0";
		cout << minutos;
	}else{
		cout << minutos;
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
