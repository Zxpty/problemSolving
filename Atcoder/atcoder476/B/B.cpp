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
	string a, b; cin >> a >> b;
	bool ok = 1;
	for(int i = 0; i < n; i++){
		if(b[i] == '*') continue;
		if(b[i] != a[i]){
			ok = 0;
		}
	}
	if(ok){
		cout << "Yes\n";
	}else{
		cout << "No\n";
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
