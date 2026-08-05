
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
	vector<int> ans = {1};
	for(int i = 1; i < n; i++){
		while(r[left] < i - left + 1){
			left++;
		}
		ans.push_back(i - left + 1);
	}
	for(int x : ans){
		cout << x << " ";
	}
	cout << '\n';
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
