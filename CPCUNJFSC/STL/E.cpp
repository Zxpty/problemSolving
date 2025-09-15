#include <bits/stdc++.h>
using namespace std;

void GA(){
	string s; cin >> s;
	int n = (int) s.size();
	int left = 0;
	int ans = 0;
	while(left < n){
		int right = left;
		int cn = 0;
		while(right < n && s[left] == s[right]) right++;
		cn = right - left;
		ans = max(ans, cn);
		left = right;
	}
	cout<< ans << '\n';
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

