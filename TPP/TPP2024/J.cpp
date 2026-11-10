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
	long long n, m; cin >> n >> m;
	if(n > m){
		cout << -1 << '\n';
		return;
	}

	int cn = 0;
	while(true){
		if(n > m){
			cout << -1 << "\n";
			return;
		}
		if(n == m) break;
		int pos = __builtin_ctzll(n);
		if(pos >= 62){
			cout << -1 << "\n";
			return;
		}
		n += (1LL << pos);
		cn++;
	}
	cout << cn << '\n';
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
