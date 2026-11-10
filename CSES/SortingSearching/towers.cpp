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
	multiset<int> st;
	vector<int> r(n);
	for(int i = 0; i < n; i++){
		cin >> r[i];
	}
	st.insert(r[0]);
	for(int i = 1; i < n; i++){
		auto it = st.upper_bound(r[i]);
		if(it == st.end()){
			st.insert(r[i]);
		}else{
			int val = *(it);
			if(r[i] < val){
				st.erase(st.find(val));
				st.insert(r[i]);
			}else{
				st.insert(r[i]);
			}
		}
	}
	cout << int(st.size()) << '\n';
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
