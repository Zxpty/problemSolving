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
	int n; cin >> n;
	vector<int> r(n);
	for(int& x : r) cin >> x;
	sort(r.begin(), r.end());
	vector<int> vis(n);
	int left = 0;
	vector<int> arr;
	while(left < n){
		int right = left;
		while(right < n && r[right] == r[left]) right++;
		arr.push_back(r[left]);
		vis[left] = 1;
		left = right;
	}

	set<int> st;
	for(int i = 0; i < n; i++){
		if(!vis[i]) st.insert(r[i]);
	}
	int ln = int(arr.size());
	ln += int(st.size());
	sort(arr.rbegin(), arr.rend());
	if(ln == n){
		cout << "YES\n";
		cout << int(st.size()) << '\n';
		for(int x : st) cout << x << " ";
		cout << '\n';
		cout << int(arr.size()) << '\n';
		for(int p : arr) cout << p << " ";
		cout << '\n';
	}else{
		cout << "NO";
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
