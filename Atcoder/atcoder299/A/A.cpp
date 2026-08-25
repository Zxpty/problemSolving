#include <bits/stdc++.h>

#ifdef local
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int mx = 1e9+7;

void uwu(){
	int n; cin >> n;
	string s; cin >> s;
	int left = 101;
	int right = -1;
	int pos = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '*') pos = i;
		if(s[i] == '|'){
			right = max(right, i);
			left = min(left, i);
		}
	}
	if(pos >= left && pos <= right){
		cout << "in";
	}else{
		cout << "out";
	}
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		uwu();
	}
	return 0;
}
