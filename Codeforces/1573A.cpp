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
	int ans = 0;
	for(int i = 0; i < n - 1; i++){
		if(s[i] != '0'){
			ans += (s[i] - '0') + 1;
		}
	}
	ans += s[n - 1] - '0';
	cout << ans << '\n';
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
