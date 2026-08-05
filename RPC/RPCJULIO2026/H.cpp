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
	string s; cin >> s;
	vector<string> r;
	string curr;
	for(char c : s){
		if(c == '!'){
			r.push_back(curr);
			curr.clear();
		}else{
			curr += c;
		}
	}
	r.push_back(curr);
	if(r.size() == 1){
		cout << r[0] << endl;
		return;
	}
	vector<string> st;
	auto convert = [&](string p){
		for(char &c : p){
			c = tolower(c);
		}
		return p;
	};
	for(int i = 0; i < int(r.size()) - 1; i++){
		string p = r[i];
		string now = convert(p);
		if(st.size() >= 2 && convert(st[st.size() - 2]) == now){
			st.pop_back();
		}else if(st.size() >= 1 && convert(st.back()) == now){
			continue;
		}else{
			st.push_back(p);
		}
	}
	st.push_back(r.back());
	for(int i = 0; i < int(st.size()); i++){
		if(i) cout << "!";
		cout << st[i];
	}
	cout << endl;
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
