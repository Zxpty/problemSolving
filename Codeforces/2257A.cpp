#include <bits/stdc++.h>
#include <cctype>

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
	set<char> st;
	vector<string> r(n);
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		st.insert(s[0]);
	}

	bool ok = 1;
	for(int i = 0; i < m; i++){
		string s; cin >> s;
		for(char c : s){
			char val = tolower(c);
			if(!st.count(val)){
				ok = 0;
			}
		}
	}
	if(ok){
		cout << "YES\n";
	}else cout << "NO\n";
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
