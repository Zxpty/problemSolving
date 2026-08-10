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
	int a;
	char b;
	int c; cin >> a >> b >> c;
	if(c >= 0 && c <= 2){
		cout << a << "-";
	}else if(c >= 3 && c <= 6){
		cout << a;
	}else{
		cout << a << "+";
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
