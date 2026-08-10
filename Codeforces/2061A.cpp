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
	vector<int> r(n);
	for(int& x : r) cin >> x;
	int odd = 0, even = 0;
	for(int x : r){
		if(x % 2 == 0) even++;
		else odd++;
	}
	int ans = 0;
	if(even >= 1){
		ans = 1 + odd;
	}else{
		ans = 1 + (odd - 2);
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
