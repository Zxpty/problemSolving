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
	stack<char> st;
	for(char c : s){
		if(!st.empty() && st.top() == c){
			st.pop();
		}else{
			st.push(c);
		}
	}
	if(st.empty()){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
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
