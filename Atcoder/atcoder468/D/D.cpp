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
	long long ans = 0;
	auto solve = [&](int left, int right){
		int bad = 0;
		int cn = 0;
		while(left >= 0 && right < n){
			if(s[left] != s[right]){
				bad++;
			}
			if(bad > 1) break;
			cn++;
			left--;
			right++;
		}
		return cn;
	};

	for(int i = 0; i < n; i++){
		ans += solve(i, i);
		ans += solve(i, i + 1);
	}
	cout << ans << "\n";
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
