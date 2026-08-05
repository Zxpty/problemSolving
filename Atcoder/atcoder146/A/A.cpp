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
	string s; cin >> s;
	if(s == "SAT"){
		cout << 1;
		return;
	}
	if(s == "FRI"){
		cout << 2;
		return;
	}
	if(s == "THU"){
		cout << 3;
		return;
	}
	if(s == "WED"){
		cout << 4;
		return;
	}
	if(s == "TUE"){
		cout << 5;
		return;
	}
	if(s == "MON"){
		cout << 6;
		return;
	}
	if(s == "SUN"){
		cout << 7;
		return;
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
