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
	int n, m, k; cin >> n >> m >> k;
	vector<int> r(n);
	for(int i = 0; i < n; i++){
		cin >> r[i];
	}
	int mn = r[0];
	int mx = r[n - 1];
	int cut = k - 1;
	vector<int> space;
	for(int i = 1; i < n; i++){
		space.push_back(r[i] - r[i - 1] - 1);
	}
	sort(space.rbegin(), space.rend());
	int ans = (mx - mn) + 1;
	for(int i = 0; i < min(cut, int(space.size())); i++){
		ans -= space[i];
	}
	cout << ans << '\n';
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
