#include <bits/stdc++.h>
using namespace std;

void GA(){
	string s; cin >> s;
	int n = (int) s.size();
	int cn = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'O') cn++;
	}
	cout << cn << '\n';
}

int main(){
	int t = 1;
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

