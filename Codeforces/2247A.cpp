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

	int pos = 0, nega = 0;
	for(int x : r) if(x > 0) pos++; else nega++;
	if(pos < nega) swap(pos, nega);
	if(pos == nega){
		cout << "Yes\n";
		return;
	}
	pos -= nega;
	if(pos > 2 && pos % 4 == 0){
		cout << "Yes\n";
		return;
	}
	cout << "No\n";
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
