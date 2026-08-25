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
	if(s == "Monday"){
		cout << 5;
	}else if(s == "Tuesday"){
		cout << 4;
	}else if(s == "Wednesday"){
		cout << 3;
	}else if(s == "Thursday"){
		cout << 2;
	}else{
		cout << 1;
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
