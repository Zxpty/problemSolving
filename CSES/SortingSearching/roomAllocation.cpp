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
	vector<pair<int, int>> times(n);
	for(int i = 0; i < n; i++){
		cin >> times[i].first;
		cin >> times[i].second;
	}
	vector<pair<int, int>> r = times;
	sort(times.begin(), times.end());
	int ans = 1;
	int habit = 1;
	set<pair<int, int>> st;
	st.insert({times[0].second, habit});
	map<pair<int, int>, multiset<int>> id;
	id[{times[0].first, times[0].second}].insert(1);
	for(int i = 1; i < n; i++){
		int arrive = times[i].first;
		auto [salida, room] = *st.begin();
		if(arrive > salida){
			st.erase(*st.begin());
			st.insert({times[i].second, room});
			id[{times[i].first, times[i].second}].insert(room);
		}else{
			habit++;
			st.insert({times[i].second, habit});
			id[{times[i].first, times[i].second}].insert(habit);
		}

	}
	cout << st.size() << "\n";
	for(auto [left, right] : r){
		cout << *id[{left, right}].begin() << " ";
		id[{left, right}].erase(id[{left, right}].begin());
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
