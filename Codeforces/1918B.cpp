#include <algorithm>
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
	vector<int> a(n), b(n);
	for(int& x : a) cin >> x;
	for(int& x : b) cin >> x;

	vector<pair<int, int>> r(n);
	for(int i = 0; i < n; i++){
		r[i] = {a[i], b[i]};
	}
	sort(r.begin(), r.end());
	for(int i = 0; i < n; i++){
		a[i] = r[i].first;
		b[i] = r[i].second;
	}
	for(int x : a) cout << x << " ";
	cout << endl;
	for(int x : b) cout << x << " ";
	cout << endl;
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
