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
	int mx = 0;
	int left = 0;
	while(left < n){
		int right = left;
		while(right < n && s[left] == s[right]) right++;
		if(s[left] == 'R'){
			mx = max(mx, right - left);
		}
		left = right;
	}
	cout << mx << '\n';
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
