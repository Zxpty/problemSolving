#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int MX = 2e5 + 5;

vector<long long> invFact, fact;
const long long MOD = 998244353;

long long binpow(long long base, long long exp){
	long long res = 1;
	while(exp > 0){
		if(exp & 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res;
}

long long modInverse(long long n){
	return binpow(n, MOD - 2);
}

long long nCr(int n, int r){
	if(r < 0 || r > n) return 0;
	return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

void init(){
	invFact.resize(MX + 1);
	fact.resize(MX + 1);
	fact[0] = 1;
	for(int i = 1; i <= MX; i++){
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	invFact[MX] = modInverse(fact[MX]);
	for(int i = MX - 1; i >= 0; i--){
		invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}
}

void UWU(){
	string s; cin >> s;
	int n = int(s.size());

	int left = 0;
	int need = 0;
	long long ans = 1;
	while(left < n){
		int right = left;
		while(right < n && s[right] == s[left]) right++;
		int ln = right - left;
		if(ln > 1){
			need += ln - 1;
			ans = (ans * ln) % MOD;
		}
		left = right;
	}
	cout << ans << endl;

	ans = (ans * fact[need]) % MOD;
	cout << need << " " << ans << "\n";

}

int main(){
	cpu();
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		UWU();
	}
	return 0;
}
