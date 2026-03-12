#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int MX = 1e9;

void ONO(){
	int n; cin >> n;
	vector<int> r(n);
	for(int i = 0; i < n; i++) cin >> r[i];
	int mx = *max_element(r.begin(), r.end());
	cout << mx << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
