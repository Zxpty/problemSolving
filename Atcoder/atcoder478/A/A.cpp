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
	vector<int> r(n);
	if(m < n){
		for(int i = 0; i < m; i++){
			r[i] = 1;
		}
	}else{
		int go = m / n;
		for(int i = 0; i < n; i++){
			r[i] = go;
		}
		int md = m % n;
		for(int i = 0; i < md; i++){
			r[i]++;
		}
	}
	for(int i = 0; i < n; i++){
		cout << r[i] << '\n';
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
