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
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}

	int first = a[n - 1];
	for(int i = 0; i + 1 < n; i++){
		first += (a[i] - a[i + 1]) + 1;
	}
	
	int second = b[m - 1];
	for(int i = 0; i + 1 < m; i++){
		second += (b[i] - b[i + 1]) + 1;
	}
	if(first == second || first > second){
		cout << "1\n";
		return;
	}
	cout << "2\n";
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
