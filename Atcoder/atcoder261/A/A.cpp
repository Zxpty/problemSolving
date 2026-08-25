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
	int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
	int mx = max(l1, l2);
	int mn = min(r1, r2);
	if(mx > mn) cout << 0;
	else cout << mn - mx;
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
