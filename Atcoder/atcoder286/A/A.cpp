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
	int n, p, q, r, s; cin >> n >> p >> q >> r >> s;
	vector<int> a(101);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		if((p <= i) && (i <= q)) cout << a[i + r - p];
		else if((r <= i) && (i <= s)) cout << a[i + p - r];
		else cout << a[i];
		if(i < n) cout << " ";
	}
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
