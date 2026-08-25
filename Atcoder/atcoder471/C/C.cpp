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
	vector<long long> r(n);
	for(int i = 0; i < n; i++) cin >> r[i];
	set<int> st(r.begin(), r.end());

	int start = 0;
	long long ans = 0;
	while(!st.empty()){
		auto it = st.upper_bound(start);
		int left = MX, right = MX;
		if(it == st.begin()){
			right = *st.begin();
		}else{
			if(it == st.end()){
				left = *prev(it);
			}else{
				right = *it;
				left = *prev(it);
			}
		}
		auto f = [&](int x){
			ans += abs(start - x);
			start = x;
			st.erase(x);
		};
		if(left != MX && right != MX){
			if(start - left <= right - start) f(left);
			else f(right);
		}else if(left == MX) f(right);
		else if(right == MX) f(left);
	}
	cout << ans;

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
