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
	vector<int> stability(n);
	for(int& x : stability) cin >> x;
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}

	int ans = m;
	multiset<int> temp;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < m; j++){
			temp.insert(grid[i][j]);
		}

		int elements = 0;
		long long acc = 0;
		for(auto it = temp.rbegin(); it != temp.rend(); it++){
			if(acc >= stability[i]){
				ans = min(ans, elements);
			}
			acc += *it;
			elements++;
			if(elements == m){
				break;
			}
		}
	}
	cout << ans << "\n";
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
