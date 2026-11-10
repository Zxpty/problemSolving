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
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		cin >> r[i];
		mp[r[i]]++;
	}
	if(mp[0] == 1){
		cout << "NO\n";
		return;
	}

	vector<char> ans(n);

	int start = 0;
	while(mp[start] >= 2){
		start++;
	}

	map<int, int> vis;
	for(int i = 0; i < n; i++){
		vis[r[i]]++;
		if(r[i] < start){
			if(vis[r[i]] == 1) ans[i] = 'A';
			else if(vis[r[i]] == 2) ans[i] = 'B';
			else ans[i] = 'C';
		}else if(r[i] == start){
			ans[i] = 'C';
		}else{
			ans[i] = 'A';
		}
	}
	cout << "YES\n";
	for(int i = 0; i < n; i++){
		cout << ans[i];
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
