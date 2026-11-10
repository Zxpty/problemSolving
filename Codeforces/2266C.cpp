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
	string s; cin >> s;
	int zero = 0;
	for(int i = 0; i < n; i++){
		zero += (s[i] == '0');
	}
	if(s[0] == '1'){
		cout << zero << '\n';
		return;
	}

	int mn = 1e9;
	int one = 0;
	for(int i = 0; i < n; i++){
		one += (s[i] == '1');
		zero -= (s[i] == '0');
		mn = min(mn, zero + one);
	}
	cout << mn << "\n";
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
