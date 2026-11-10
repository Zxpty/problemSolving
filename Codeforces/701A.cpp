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
	vector<int> r(n);
	vector<int> vis(n);
	int acc = 0;
	for(int i = 0; i < n; i++){
		cin >> r[i];
		acc += r[i];
	}
	int sum = acc / (n / 2);
	for(int i = 0; i < n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		for(int j = i + 1; j < n; j++){
			if(vis[j]) continue;
			if(r[i] + r[j] == sum){
				cout << i + 1 << " " << j + 1 << '\n';
				vis[j] = 1;
				break;
			}
		}
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
