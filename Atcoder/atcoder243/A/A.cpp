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
	int v, a, b, c; cin >> v >> a >> b >> c;
	v %= (a + b + c);
	if(v < a){
		cout << "F";
	}else if(v < (a + b)){
		cout << "M";
	}else{
		cout << "T";
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
