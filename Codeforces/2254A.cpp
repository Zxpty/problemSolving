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
	vector<int> r(3);
	for(int& x : r) cin >> x;
	int ans = 0;
	while(true){
		sort(r.begin(), r.end());
		if(r[0] == r[1] || r[1] == r[2]) break;
		r[0]++;
		r[2]--;
		ans++;
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
