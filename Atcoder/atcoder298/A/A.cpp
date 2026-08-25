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

	bool ok = false;
	for(int i = 0; i < n; i++) if(s[i] == 'o') ok = 1;
	bool ok2 = true;
	for(int i = 0; i < n; i++) if(s[i] == 'x') ok2 = 0;

	if(ok && ok2) cout << "Yes";
	else cout << "No";
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
