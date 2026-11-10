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
	string s; cin >> s;
	sort(s.begin(), s.end());
	vector<string> ans;
	do{
		ans.push_back(s);
	}while(next_permutation(s.begin(), s.end()));
	cout << int(ans.size()) << endl;
	for(auto s : ans){
		cout << s << endl;
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
