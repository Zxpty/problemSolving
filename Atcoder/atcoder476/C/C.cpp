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

	priority_queue<int> pq;
	pq.push(r[0]);
	pq.push(r[1]);
	for(int i = 2; i < n; i++){
		pq.push(r[i]);
		int first = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();
		int third = pq.top(); pq.pop();
		cout << third << "\n";
		pq.push(first);
		pq.push(second);
		pq.push(third);
	}

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
