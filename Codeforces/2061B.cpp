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
	set<int> st(r.begin(), r.end());
	int sz = int(st.size());
	map<int, int> mp;
	for(int x : r) mp[x]++;
	bool ok = 0;
	int num = -1;
	for(auto [val, freq] : mp){
		if(freq >= 2){
			ok = 1;
			num = val;
			break;
		}
	}
	if(!ok){
		cout << -1 << '\n';
		return;
	}

	if(sz == 2){
		vector<int> two(st.begin(), st.end());
		int first = two[0];
		int second = two[1];
		if(mp[first] >= 2 && mp[second] >= 2){
			cout << first << " " << first << " " << second << " " << second << "\n";
		}else{
			cout << -1 << "\n";
		}
		return;
	}
	if(sz == 1){
		vector<int> one(st.begin(), st.end());
		int first = one[0];
		if(mp[first] >= 4){
			cout << first << " " << first << " " << first << " " << first << "\n";
		}else{
			cout << -1 << "\n";
		}
		return;
	}
	vector<int> three(st.begin(), st.end());
	cout << num << " " << num << " ";
	int cn = 0;
	for(int x : three){
		if(x == num) continue;
		if(cn == 2){
			break;
		}
		cout << x << " ";
		cn++;
	}
	cout << "\n";
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
