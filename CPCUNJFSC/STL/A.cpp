#include <bits/stdc++.h>
using namespace std;

void GA(){
	string s; cin>> s;
	int n = (int) s.size();
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += s[i] - '0';
	}
	cout<< sum << '\n';

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
