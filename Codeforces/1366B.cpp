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
	int n, x, m; cin >> n >> x >> m;
	int left = x, right = x;
	vector<int> L(m), R(m);
	for(int i = 0; i < m; i++){
		 cin >> L[i] >> R[i];
	}

	for(int i = 0; i < m; i++){
		if(R[i] >= left && L[i] <= right){
			left = min(left, L[i]);
			right = max(right, R[i]);
		}
	}
	cout << right - left + 1 << '\n';
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
