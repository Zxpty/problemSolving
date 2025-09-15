#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<vector<int>> v(n, vector<int>(5));
  for (auto& x : v) for (int& i : x) cin >> i;
  
  int y = 0, ier = 0, est = 1;
  vector<int> mx(v[0].begin(), v[0].end());
  for (int i = 1; i < n; i++) {
    int count = 0;
    for (int j = 0; j < 5; j++) {
		if (v[i][j] > mx[j]){
			mx[j] = v[i][j];
			count++;
		}
    }
    if (count > 2) {
      if (count == 3) y++;
      else if (count == 4) ier++;
      else if (count == 5) est++;
    }
  }

  cout << y << ' ' << ier << ' ' << est << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; 
  //cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
