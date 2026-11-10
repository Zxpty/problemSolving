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

	vector<long long> ans(n);
	bool cn = 0;
	for(int i = 0; i < n; i++){
		if(a[i] <= b[i]){
			ans[i] = 1;
		}else{
			ans[i] = 1e18;
			cn = 1;
		}
	}
	if(cn){
		cout << "Yes\n";
		for(auto x : ans){
			cout << x << " ";
		}
	}else{
		cout << "No\n";
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
