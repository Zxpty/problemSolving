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
	int pos = 0;
	string num;
	for(int i = 0; i < int(s.size()); i++){
		if(s[i] == '.'){
			pos = i;
			break;
		}
		num += s[i];
	}
	int val = s[pos + 1] - '0';
	if(val < 5){
		cout << num;
	}else{
		int other = stoi(num);
		other++;
		cout << other;
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
