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
	char a = s[0];
	char b = s[1];
	char c = s[2];
	string first;
	first += b;
	first += c;
	first += a;

	string second;
	second += c;
	second += a;
	second += b;
	cout << first << " " << second;
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
