#include <algorithm>
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
	int n, q; cin >> n >> q;
	vector<int> pos(n);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		x--;
		pos[x] = i;
	}

	int start = n;
	for(int i = 0; i < q; i++){
		int x; cin >> x;
		x--;
		pos[x] = start++;
	}
	vector<pair<int, int>> res;
	for(int i = 0; i < n; i++){
		res.push_back({pos[i], i});
	}
	sort(res.begin(), res.end());
	for(auto [pos, num] : res){
		cout << num + 1 << " ";
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
