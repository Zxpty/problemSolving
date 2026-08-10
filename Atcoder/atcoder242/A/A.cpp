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
	int a, b, c, x; cin >> a >> b >> c >> x;
	if(x <= a){
		cout << "1.0";
	}else if(x <= b){
		double res = c;
		res /= (b - a);
		cout << res;
	}else{
		cout << "0.0";
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
