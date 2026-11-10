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
	string a, b; cin >> a >> b;
	if(a[0] == 'A' && (a[1] == 'D' || b[0] == 'D')){
		cout << "Yes\n";
		return;
	}
	if(a[1] == 'A' && (a[0] == 'D' || b[1] == 'D')){
		cout << "Yes\n";
		return;
	}
	if(b[1] == 'A' && (b[0] == 'D' || a[1] == 'D')){
		cout << "Yes\n";
		return;
	}
	if(b[0] == 'A' && (a[0] == 'D' || b[1] == 'D')){
		cout << "Yes\n";
		return;
	}

	cout << "No\n";
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
