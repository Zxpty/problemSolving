#include <bits/stdc++.h>
using namespace std;

void GA(){
	int n; cin >> n;
	set<int> st;
	for(int i = 0; i < n; i++){
		int num; cin >> num;
		st.insert(num);
	}
	cout << (int) st.size() << '\n';
}

int main(){
	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

