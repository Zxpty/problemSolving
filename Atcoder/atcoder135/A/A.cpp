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
	long long a, b; cin >> a >> b;
	if(a > b) swap(a, b);
	long long first = a + b;
	if(first % 2 == 0){
		cout << first / 2;
		return;
	}
	long long second = b - a;
	if(second % 2 == 0){
		cout << second / 2;
		return;
	}
	cout <<"IMPOSSIBLE";
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
