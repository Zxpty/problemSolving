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
	int n, k; cin >> n >> k;
	vector<int> r(n);
	for(int& x : r) cin >> x;

	stack<int> st;

	vector<int> p;
	for(int i = 0; i < n; i++){
		if(st.empty() || st.top() != r[i]){
			st.push(r[i]);
		}else{
			p.push_back(st.top());
			st.pop();
		}
	}


	sort(p.begin(), p.end());

	if(int(p.size()) < k){
		cout << -1 << '\n';
		return;
	}

	long long ans = 0;
	int m = int(p.size());
	for(int i = m - 2; i >= m - k; i--){
		ans += p[i];
	}
	if(m > k){
		ans += 1LL * p.back() * (m - k + 1);
	}else{
		ans += p.back();
	}
	cout << ans << "\n";

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
