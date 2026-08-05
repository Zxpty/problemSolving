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
	char letter; cin >> letter;
	if(letter == 'A'){
		cout << "T";
		return;
	}
	if(letter == 'T'){
		cout << "A";
		return;
	}
	if(letter == 'C'){
		cout << "G";
		return;
	}
	if(letter == 'G'){
		cout << "C";
		return;
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
