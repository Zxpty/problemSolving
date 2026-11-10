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

	auto check = [&](char c){
		return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	};

	int n = int(s.size());
	set<string> st;
	for(int i = 0; i <= n - 5; i++){
		if(s[i] == s[i + 4] && check(s[i]) && s.substr(i + 1, 3) == "GAS"){
			string t = s.substr(0, i + 1) + s.substr(i + 5);
			st.insert(t);
		}
	}
	if(st.empty()){
		cout << "-\n";
	}else if(int(st.size()) == 1){
		cout << *st.begin() << '\n';
	}else{
		cout << "+\n";
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
