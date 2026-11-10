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
	vector<long long> r(n);
	for(auto& x : r) cin >> x;
	long long y = accumulate(r.begin(), r.end(), 0LL);
	
	long long best = r[1], sum = r[1];
	for(int k = 2; k < n; k++){
		sum = max(r[k], sum + r[k]);
		best = max(sum, best);
	}
	long long other = r[0];
	long long acc = r[0];
	for(int k = 1; k < n - 1; k++){
		acc = max(r[k], acc + r[k]);
		other = max(acc, other);
	}

	long long mx = max(other, best);
	//cout << mx << " " << y << endl;
	if(mx >= y){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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
