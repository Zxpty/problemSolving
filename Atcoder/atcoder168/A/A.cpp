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
	int last = n % 10;
	for(int x : {2, 4, 5, 7, 9}){
		if(last == x){
			cout << "hon";
			return;
		}
	}
	for(int x : {0, 1, 6, 8}){
		if(last == x){
			cout << "pon";
			return;
		}
	}

	cout << "bon";
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
