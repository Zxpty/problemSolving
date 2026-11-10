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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int left = 0;
	int ans = 0;
	while(left < n){
		int right = left;
		int zero = 0;
		while(right < n && right - left < k){
			if(s[right] == '0') zero = 1;
			right++;
		}
		if(!zero) ans++;
		left = right;
	}
	cout << ans << "\n";
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
