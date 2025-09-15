#include <bits/stdc++.h>
#include <ostream>
using namespace std;

void GA(){
	string s; cin>> s;
	int n = s.size();
	int left = 0;
	int ans = 0;
	while(left < n){
		int right = left;
		while(right < n && s[left] == s[right]) right++;
		ans = max(ans, right - left);
		left = right;
	}
	cout << ans;
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

