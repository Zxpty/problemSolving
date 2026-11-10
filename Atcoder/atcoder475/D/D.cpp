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
bool isPrime(long long x){
	if(x < 2) return false;
	for(long long i = 2; i * i <= x; i++){
		if(x % i == 0) return false;
	}
	return true;
}
void UWU(){
	string s; cin >> s;
	map<char, int> id;
	vector<int> r;

	int k = 0;
	for(char c : s){
		if(!id.count(c)){
			id[c] = k;
			k++;
		}
		r.push_back(id[c]);
	}

	vector<int> dig(10);
	iota(dig.begin(), dig.end(), 0);
	vector<int> p = dig;
	do{
		if(p[r[0]] == 0) continue;
		long long num = 0;
		for(int x : r){
			num = num * 10 + p[x];
		}
		if(isPrime(num)){
			cout << num << "\n";
			return;
		}
	}while(next_permutation(p.begin(), p.end()));
	cout << -1;
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
