#include <algorithm>
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
	string s; cin >> s;
	int one = count(s.begin(), s.end(), '1');
	int zero = n - one;

	int mn = min(one, zero);
	int calc = n - (mn + (mn + 1));
	if(calc > 1){
		cout << "-1" << '\n';
		return;
	}

	int g = 0;
	int left = 0;
	int need_one = 0, need_zero = 0;

	while(left < n){
		int right = left;
		while(right < n && s[left] == s[right]) right++;
		if(s[left] == '0'){
			need_zero += (right - left - 1);
		}else{
			need_one += (right - left - 1);
		}
		left = right;
	}

	int first = max(need_zero, need_one - 1);
	int second = max(need_one, need_zero - 1);

	if(first > zero || second > one){
		cout << "-1" << '\n';
		return;
	}
	cout << first + second << "\n";


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
