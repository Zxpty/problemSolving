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
	vector<int> a(n);
	for(int& x : a) cin >> x;
	vector<int> b(n);
	for(int& x : b) cin >> x;
	vector<int> r = a;
	sort(r.begin(), r.end());
	int cn = 0;
	do{
		if(r > a && r < b) cn++; 
	}while(next_permutation(r.begin(), r.end()));
	cout << cn;
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
