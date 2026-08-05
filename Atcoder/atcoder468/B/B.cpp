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
	string s; cin >> s;
	vector<int> vis(n);
	for(int i = 0; i < n; i++){
		if(s[i] == 'G'){
			int left = i;
			int right = i;
			left = max(i - d, 0);
			right = min(n - 1, right + d);
			//dbg(left, right);
			for(int j = left; j <= i; j++){
				vis[j] = 1;
			}
			for(int j = i; j <= right; j++){
				vis[j] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'G') continue;
		if(!vis[i]) ans++;
	}
	cout << ans;
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
