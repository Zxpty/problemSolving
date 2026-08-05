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

	int left = 0;
	int ans = 0;
	while(left < n){
		int right = left;
		while(right < n && s[left] == s[right]) right++;
		if(s[left] == 'R'){
			ans = max(right - left, ans);
		}
		left = right;
	}
	cout << ans;
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
