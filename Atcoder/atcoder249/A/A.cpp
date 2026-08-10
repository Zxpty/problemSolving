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
	int a, b, c, d, e, f, x; cin >> a >> b >> c >> d >> e >> f >> x;
	int t = 0, ao = 0;
	for(int k = 0; k < x; k++){
		if(k % (a + c) < a){
			t += b;
		}
		if(k % (d + f) < d){
			ao += e;
		}
	}
	if(t > ao) cout << "Takahashi";
	else if(t < ao) cout << "Aoki";
	else cout << "Draw";
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
