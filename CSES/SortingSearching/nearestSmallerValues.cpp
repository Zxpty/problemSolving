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
	set<pair<int, int>> st;
	for(int i = 0; i < n; i++){
		while(!st.empty() && st.rbegin()->first >= r[i]){
			st.erase(prev(st.end()));
		}
		if(st.empty()){
			cout << 0 << " ";
		}else{
			cout << st.rbegin()->second << " ";
		}
		st.insert({r[i], i + 1});
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
