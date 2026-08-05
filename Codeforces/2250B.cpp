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
	int n, k; cin >> n >> k;
	int first = n / 2;
	int second = n - first;
	int total = (first - 1) + (second - 1);
	if(total < k){
		cout << -1 << '\n';
		return;
	}
	int b = n - k;
	int b0 = b / 2;
	int b1 = b / 2;
	int start = 0;
	if(b % 2 == 1){
		if(first > second){
			b0++;
			start = 0;
		}else{
			b1++;
			start = 1;
		}
	}
	vector<int> zero(b0, 1);
	if(b0 > 0) zero[0] += (first - b0);
	vector<int> one(b1, 1);
	if(b1 > 0) one[0] += (second - b1);
	int left = 0, right = 0;
	for(int i = 0; i < b; i++){
		if(start == 0){
			for(int j = 0; j < zero[left]; j++) cout << "0";
			left++;
			start = 1;
		}else{
			for(int j = 0;j < one[right]; j++) cout << "1";
			right++;
			start = 0;
		}
	}
	cout << '\n';
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
