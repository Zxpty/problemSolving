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
	int n = int(s.size());
	int need = 3 - n;
	cout << "AGC";
	for(int i = 0; i < need; i++) cout << "0";
	int val = stoi(s);
	if(val >= 42) cout << val + 1;
	else cout << val;
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
