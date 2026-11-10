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
	vector<pair<int, int>> r(n);
	for(int i = 0; i < n; i++){
		int start, end; cin >> start >> end;
		r[i].first = start;
		r[i].second = end;
	}
	sort(r.begin(), r.end(), [&](auto a, auto b){
			return a.second < b.second;
			});

	int mx = 1;
	int end_before = r[0].second;
	for(int i = 1; i < n; i++){
		int start_now = r[i].first;
		int end_now = r[i].second;
		if(start_now >= end_before){
			end_before = end_now;
			mx++;
		}
	}
	cout << mx << '\n';

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
