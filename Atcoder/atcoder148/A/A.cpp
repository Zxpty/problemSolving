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
	set<int> st;
	int a, b; cin >> a >> b;
	st.insert(a);
	st.insert(b);
	for(int i = 1; i <= 3; i++)if(!st.count(i)){
		cout << i;
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
