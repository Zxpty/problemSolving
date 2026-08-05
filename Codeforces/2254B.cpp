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
	int cn = 1;
	for(int i = 1 ; i < n; i++){
		if(s[i] != s[i - 1]) cn++;
	}
	int ans = cn;
	for(int i = 1; i < n - 1; i++){
		if(s[i] != s[i - 1] && s[i] != s[i + 1]){
			if(s[i - 1] == s[i + 1]){
				ans = min(ans, cn - 2);
			}else{
				ans = min(ans, cn - 1);
			}
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
