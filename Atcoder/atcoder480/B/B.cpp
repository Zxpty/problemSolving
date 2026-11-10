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
	vector<string> a(n), b(m);
	for(auto& x : a) cin >> x;
	for(auto& x : b) cin >> x;

	vector<int> ans(n);
	for(int i = 0; i < m; i++){
		string s = b[i];
		int idx = -1;
		for(int j = 0; j < n; j++){
			if(s == a[j]) idx = j;
		}
		if(idx != -1){
			ans[idx]++;
			continue;
		}
		int check = 0;
		for(int j = 0; j < n; j++){
			if(int(a[j].size()) != int(s.size())) continue;
			int cn = 0;
			for(int k = 0; k < int(s.size()); k++){
				cn += a[j][k] != s[k];
			}
			if(cn == 1){
				idx = j;
				check++;
			}
		}
		if(idx != -1 && check == 1) ans[idx]++;
	}

	for(int i = 0; i < n; i++){
		cout << ans[i] << "\n";
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
