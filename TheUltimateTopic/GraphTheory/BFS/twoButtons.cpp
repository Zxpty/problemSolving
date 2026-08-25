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
	queue<pair<int, int>> q;
	q.push({n, 0});
	while(!q.empty()){
		auto [val, dis] = q.front();
		q.pop();
		if(val == m){
			cout << dis << "\n";
			return;
		}
		if(val * 2 < 20000) {
			q.push({val * 2, dis + 1});
		}
		if(val - 1 > 0){
			q.push({val - 1, dis + 1});
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
