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
	int n, m; cin >> n >> m;
	auto get_cn_div = [&](int x, int div){
		int cn = 0;
		while(x % div == 0){
			cn++;
			x /= div;
		}
		return cn;
	};

	int div5 = get_cn_div(n, 5);
	int div2 = get_cn_div(n, 2);

	long long M = 1;
	if(div5 > div2){
		while(M * 2 <= m && div2 < div5){
			M *= 2;
			div2++;
		}
	}
	if(div2 > div5){
		while(M * 5 <= m && div5 < div2){
			M *= 5;
			div5++;
		}
	}
	while(M * 10 <= m) M *= 10;

	for(int i = m / M; i > 1; i--){
		while(M * i <= m) M *= i;
	}
	cout << M * n << "\n";


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
