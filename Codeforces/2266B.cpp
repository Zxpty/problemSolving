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
	long long a, b, c; cin >> a >> b >> c;

	if(a >= b){
		cout << (a + c) - b << '\n';
	}else{
		long long first = b - a;
		first = max(first, (a + c) - b);
		cout << first << "\n";
	}
	
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
