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
	int year;
	char a;
	int month;
	char b;
	int day;
	cin >> year >> a >> month >> b >> day;
	if(year > 2019){
		cout << "TBD";
		return;
	}
	if(month > 4){
		cout << "TBD";
		return;
	}
	if(day > 30){
		cout << "TBD";
		return;
	}

	cout << "Heisei";
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
