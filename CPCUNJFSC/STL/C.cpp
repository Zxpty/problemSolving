#include <bits/stdc++.h>
using namespace std;

void GA(){
	string s; cin >> s;
	int n = (int) s.size();
	if(n == 1){
		cout<< 1 << '\n';
		return;
	}
	int left = 0;
	while(left < n){
		int right = left;
		while(right < n && s[left] == s[right]){
			right++;
		}
		cout<<right - left<< s[left];
		left = right;
	}
	cout << '\n';
}

int main(){
	int t = 1;
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

