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
	long long x, y; cin >> x >> y;
	// a + b = (a xor b) + 2(a & b);
	long long sum = x + y;
	long long mn = 0;
	for(int i = 29; i >= 0; i--){
		if((sum >> i) & 1){
			if(mn + (1LL << i) <= x){
				mn += (1LL << i);
			}
		}
	}
	cout << sum << " " << (x - mn) << '\n';

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
