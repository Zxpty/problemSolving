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
	char change; cin >> change;
	string s; cin >> s;
	int left = 0, right = n - 1;
	int ans = 0;
	while(left < right){
		if(s[right] == s[left]){
			left++;
			right--;
		}else{
			if(s[right] == change || s[left] == change) ans++;
			else ans += 2;
			left++;
			right--;
		}
	}
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
