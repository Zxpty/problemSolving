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

	int left = 0;
	if(r[0] == 1) left++;
	if(r[n - 1] == 1) left++;

	int cn = 0;
	for(int i = 1; i < n - 1; i++){
		if(r[i] == 0) cn++;
	}
	if(cn >= left){
		cout << left << "\n";
	}else{
		cout << -1 << "\n";
	}

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
