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
	vector<int> r(n);
	for(int& x : r) cin >> x;

	vector<int> ten, twelve;

	for(int i = 0; i < n; i++){
		if(r[i] % 10 == 0){
			ten.push_back(r[i]);
		}else if(r[i] % 5 == 0){
			ten.push_back(r[i] + 5);
		}else{
			while(r[i] % 10 != 2){
				r[i] = r[i] + (r[i] % 10);
			}
			twelve.push_back(r[i]);
		}
	}
	int p = int(ten.size()), q = int(twelve.size());

	/*cout << "---------ten-------\n";
	for(int x : ten){
		cout << x << " ";
	}
	cout << endl;
	cout << "---------ten-------\n";

	cout << "---------twenty-------\n";
	for(int x : twelve){
		cout << x << " ";
	}
	cout << endl;
	cout << "---------twenty-------\n";

	*/



	if(p > 0 && q > 0){
		cout << "NO"<< "\n";
	}else if(p > 0){
		sort(ten.begin(), ten.end());
		if(ten[0] == ten[p - 1]){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}else if(q > 0){
		bool ok = 1;
		sort(twelve.begin(), twelve.end());
		for(int i = 1; i < int(twelve.size()); i++){
			if((twelve[i] - twelve[i - 1]) % 20 != 0){
				ok = 0;
				break;
			}
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
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
