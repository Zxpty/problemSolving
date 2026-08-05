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
	int a, b; cin >> a >> b;
	auto get = [&](int x){
		int sum = 0;
		while(x > 0){
			sum += (x % 10);
			x /= 10;
		}
		return sum;
	};
	int first = get(a);
	int second = get(b);
	cout << max(first, second);

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
