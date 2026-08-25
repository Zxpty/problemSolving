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
	int n, target; cin >> n >> target;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	multiset<int> st(a.begin(), a.end());
	int fill = target;
	int height = 1;
	while(!st.empty()){
		auto it = st.upper_bound(fill);
		if(it != st.begin()) --it;
		if(fill - *it < 0){
			fill = target;
			height++;
		}
		fill -= *it;
		st.erase(it);

	}
	cout << height << '\n';

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
