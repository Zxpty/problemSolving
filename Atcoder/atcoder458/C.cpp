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
	string s; cin >> s;
	int n = int(s.size());
	long long cn = count(s.begin(), s.end(), 'C');
	for(int i = 0; i < n; i++){
		if(s[i] == 'C'){
			dbg(i, n - i - 1);
			cn += min(i, n - i - 1);
		}
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
