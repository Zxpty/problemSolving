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
	vector<int> r(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> r[i];
	}
	int left = 1;
	int right = 10;
	for(int i = 1; i <= n; i++){
		if(i > 1 && i % 10 == 1){
			//cout << left << " " << right << "\n";
			left = right + 1;
			right += 10;

		}
		if(r[i] < left || r[i] > right){
			//cout << "==========\n";
			//cout << left << " " << right << '\n';
			//cout << r[i] << endl;
			//cout << "==========\n";
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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
