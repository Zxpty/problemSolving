#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 2e5 + 5;

void UWU(){
	string s; cin >> s;
	int n = int(s.size());
	vector<int> pre(n), suff(n);
	int left = 0;
	vector<int> a(n);
	while(left < n){
		int right = left;
		while(right < n && s[left] == s[right]) right++;
		if(s[left] == 'v'){
			int ln = right - left;
			if(ln == 1) a[left] = 0;
			else{
				for(int i = left + 1; i < right; i++){
					a[i] = 1;
				}
			}
		}
		left = right;
	}

	pre[0] = a[0];
	suff[n - 1] = a[n - 1];
	for(int i = 1; i < n; i++){
		pre[i] = pre[i - 1] + a[i];
	}
	for(int i = n - 2; i >= 0; i--){
		suff[i] = suff[i + 1] + a[i];
	}

	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'o'){
			long long l = pre[i];
			long long r = suff[i];
			ans += l * r;
		}
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
