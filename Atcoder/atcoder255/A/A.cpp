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
	int r, c; cin >> r >> c;
	r--, c--;
	vector<vector<int>> p(2, vector<int>(2));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			cin >> p[i][j];
		}
	}
	cout << p[r][c];
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
