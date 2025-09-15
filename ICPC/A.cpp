#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
void GA(){
	int n; cin >> n;
	long long sum = 0;
 	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for(int i = 0; i < n; i++){
		long long num; cin >> num;
		pq.push(num);
	}
	while(pq.size() > 1){
		long long first = pq.top(); pq.pop();
		long long second = pq.top();pq.pop();
		pq.push(first + second);
		sum += first + second;
	}
	cout << sum << '\n';
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
