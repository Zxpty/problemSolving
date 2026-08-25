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
	int n, x; cin >> n >> x;
	string s;
	for(char c = 'A'; c <= 'Z'; c++){
		for(int i = 0; i < n; i++){
			s += c;
		}
	}
	cout << s[x - 1];
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
