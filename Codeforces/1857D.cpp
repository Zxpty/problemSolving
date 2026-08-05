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
	vector<long long> a(n), b(n);
	for(auto& x : a) cin >> x;
	for(auto& x : b) cin >> x;

	vector<int> res(n);
	for(int i = 0; i < n; i++){
		res[i] = a[i] - b[i]; 
	}
	long long mx = *max_element(res.begin(), res.end());
	vector<long long> ans;
	for(int i = 0; i < n; i++){
		if(res[i] == mx){
			ans.push_back(i + 1);
		}
	}
	sort(ans.begin(), ans.end());
	cout << int(ans.size()) << '\n';
	for(auto x : ans){
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
