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
	int n, d; cin >> n >> d;
	vector<int> r(n);
	for(int& x : r) cin >> x;
	vector<int> ans;
	for(int i = 0; i < n; i++){
		bool ok = 1;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			if(abs(r[i] - r[j]) < d){
				ok = 0;
			}
		}
		if(ok){
			ans.push_back(i);
		}
	}
	cout << int(ans.size()) << '\n';
	sort(ans.begin(), ans.end());
	for(int x : ans){
		cout << x + 1 << " ";
	}
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
