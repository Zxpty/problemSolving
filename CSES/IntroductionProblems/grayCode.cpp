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
	vector<string> ans;
	for(int mask = 0; mask < (1 << n); mask++){
		string s;
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)) s += '1';
			else s += '0';
		}
		reverse(s.begin(), s.end());
		ans.push_back(s);
	}
	auto check = [&](string a, string b){
		int diff = 0;
		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i]){
				diff++;
			}
		}
		return diff == 1;
	};
	sort(ans.begin(), ans.end(), [&](auto a, auto b){
			return check(a, b);
			});
	reverse(ans.begin(), ans.end());
	for(string s : ans){
		cout << s << '\n';
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
