#include <bits/stdc++.h>
using namespace std;

void GA(){
	int n; cin >> n;
	vector<int> r(n - 1);
	for(int i = 0; i < n - 1; i++){
		cin>>r[i];
	}
	vector<int> freq(n + 1);
	for(int i = 0; i < n; i++){
		freq[r[i]]++;
	}

	for(int i = 1; i <= n; i++){
		if(freq[i] == 0){
			cout << i;
			return;
		}
	}
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

