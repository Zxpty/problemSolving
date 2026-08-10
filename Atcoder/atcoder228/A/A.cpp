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
	int s, t, x; cin >> s >> t >> x;
	if(s < t){
		cout << (s <= x && x < t ? "Yes" : "No");
	}else{
		cout << (x < t or s <=x  ? "Yes" : "No");
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
