#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

set<long long> st;

void init(){
	for(long long k = 2; k <= 1000; k++){
		long long val = 1 + k;
		long long pot = k * k;
		for(int limit = 2; limit <= 20; limit++){
			val += pot;
			if(val > 1e6) break;
			st.insert(val);
			pot *= k;
		}
	}
}

void UWU(){
	long long n; cin >> n;
	if(st.count(n)){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}

}

int main(){
	cpu();
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
