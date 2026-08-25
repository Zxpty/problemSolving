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
	vector<int> a(100);
	vector<string> s(100);
	for(int i = 0; i < n; i++) cin >> s[i] >> a[i];
	pair<int, int> m = {a[0], 0};
	for(int i = 1; i < n; i++) m = min(m, {a[i], i});
	int p = m.second;
	for(int i = 0; i < n; i++) cout << s[(p + i) % n] << endl;
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
