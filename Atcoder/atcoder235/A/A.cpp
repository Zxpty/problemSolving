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
	string a; cin >> a;
	string b, c;
	b += a[1];
	b += a[2];
	b += a[0];
	c += a[2];
	c += a[0];
	c += a[1];

	int first = stoi(a);
	int second = stoi(b);
	int third = stoi(c);
	cout << first + second + third;

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
