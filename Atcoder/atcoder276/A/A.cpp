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
	int n = int(s.size());
	int pos = -1;
	for(int i = 0; i < n; i++){
		if(s[i] == 'a'){
			pos = i;
		}
	}
	if(pos != -1){
		cout << pos + 1;
	}else{
		cout << pos;
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
