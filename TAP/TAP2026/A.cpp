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
	int h, m, s; cin >> h >> m >> s;
	int total = s;
	total += (m * 60);
	total += (h * 60 * 60);

	int mid = (2 * 60 * 60);
	mid += (30 * 60);

	if(total == mid){
		cout << "=";
	}else if(total < mid){
		cout << "-";
	}else{
		cout << "+";
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
