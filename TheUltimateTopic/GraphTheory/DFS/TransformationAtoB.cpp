#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 1e9+7;

bool solve(long long a, long long b, vector<long long>& path){
	if(a > b) return false;
	path.push_back(a);
	if(a == b){
		return true;
	}
	if(solve(a * 2, b, path)) return true;
	if(solve(a * 10 + 1, b, path)) return true;
	path.pop_back();
	return false;
}

void UWU(){
	long long a, b; cin >> a >> b;
	vector<long long> path;
	if(solve(a, b, path)){
		cout << "YES\n";
		cout << int(path.size()) << "\n";
		for(auto x : path){
			cout << x << " ";
		}
	}else{
		cout << "NO\n";
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
