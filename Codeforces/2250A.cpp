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
	if(n % 2 != 0){
		cout << "NO\n";
		return;
	}
	int left = -1e9;
	int right = 1e9;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) right = min(right, r[i]);
		else left = left = max(left, r[i]);
	}
	//cout << left << " " << right;
	if(left + 1 < right){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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
