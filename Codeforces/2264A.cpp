#include <bits/stdc++.h>
#include <utility>

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

	vector<int> bad;
	for(int i = 0; i < n; i++){
		if(r[i] != i + 1){
			bad.push_back(i);
		}
	}
	for(int i = 0; i < int(bad.size()) / 2; i++){
		swap(r[bad[i]], r[bad[int(bad.size()) - 1 - i]]);
	}

	for(int i = 1; i < n; i++){
		if(r[i - 1] > r[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
