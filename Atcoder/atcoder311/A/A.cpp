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
	string s; cin >> s;
	vector<int> ans;
	for(int i = 0; i < n; i++){
		if(s[i] == 'A'){
			ans.push_back(i);
			break;
		}
	}
	for(int i = 0; i < n; i++){
		if(s[i] == 'B'){
			ans.push_back(i);
			break;
		}
	}
	for(int i = 0; i < n; i++){
		if(s[i] == 'C'){
			ans.push_back(i);
			break;
		}
	}
	sort(ans.rbegin(), ans.rend());
	cout << ans[0] + 1;
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
