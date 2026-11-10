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
	vector<string> r(5);
	for(auto& x : r) cin >> x;
	int mx = 10;
	for(int i = 0; i < 5; i++){
		int row = 0;
		int col = 0;
		for(int j = 0; j < 5; j++){
			if(r[i][j] == '.') row++;
			if(r[j][i] == '.') col++;
		}
		mx = min(mx, row);
		mx = min(mx, col);
	}

	int right = 0;
	for(int i = 0; i < 5; i++){
		right += (r[i][i] == '.');
	} 
	mx = min(right, mx);

	int left = 0;
	for(int i = 0; i < 5; i++){
		left += (r[i][5 - i - 1] == '.');
	}
	mx = min(mx, left);
	cout << mx << "\n";
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
