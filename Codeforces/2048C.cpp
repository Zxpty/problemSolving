#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9;

void ONO(){
	string s; cin >> s;
	int n = int(s.size());
	int pos = -1;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			pos = i;
			break;
		}
	}

	string mn = "0";
	auto fx = [&](string a, string b) -> bool{
		if(int(a.size()) > int(b.size())) return 0;
		if(int(a.size()) < int(b.size())) return 1;
		return b > a;
	};
	if(pos == -1){
		cout << 1 << " " << n << " "<< 1 << " " << 1 << '\n';
		return;
	}

	pair<int, int> ans = {1, 1};

	int dis = n - pos;
	for(int i = 0; i + dis <= n; i++){
		string other = string(n - dis, '0') + s.substr(i, dis);
		string res;
		for(int i = 0; i < n; i++){
			res += (other[i] == s[i] ? '0' : '1');
		}
		if(fx(mn, res)){
			mn = res;
			ans.first = i + 1;
			ans.second = i + dis;
		}
	}
	cout << 1 << " " << n << " " << ans.first << " " << ans.second << '\n';
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
