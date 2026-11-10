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
	for(int& x : r) cin >> x;
	vector<int> ans;
	ans.push_back(r[0]);
	int direction = 0;
	for(int i = 1; i < n; i++){
		int new_direction;
		if(r[i] > r[i - 1]){
			new_direction = 1;
		}else{
			new_direction = -1;
		}
		if(direction == 0){
			direction = new_direction;
		}else if(new_direction != direction){
			ans.push_back(r[i - 1]);
			direction = new_direction;
		}
	}
	ans.push_back(r.back());
	cout << int(ans.size()) << '\n';
	for(int x : ans){
		cout << x << " ";
	}
	cout << '\n';
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
