#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);}
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.first, p.second);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.first, ", ", x.second, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.first, ' ', x.second); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}

const int MX = 1e6;
const int MOD = 1e7 + 7;
vector<long long> cnt(MX + 1, 0);

vector<pair<int, int>> factor(vector<int> primes, int n) {
	vector<pair<int, int>> ans;
	for(auto x : primes){
		int exp = 0;
		int value = n;
		while(value){
			value /= x;
			exp += value;
		}
		ans.push_back({x, exp});
	}
	return ans;
}


template<typename T>
vector<int> factor(T x) {
	vector<int> ans;
	for(T i = 2; i * i <= x; i++)
		if(x % i==0) {
			ans.push_back(1);
			while((x /= i) % i == 0) ans.back()++;
		}
	if(x != 1) ans.push_back(1);
	return ans;
}


void pre(){
	for(int i = 1; i <= MX; i++){
		vector<int> facts = factor(i);
		long long res = 1;
		for(int x : facts){
			res *= (x + 1);
		}
		cnt[i] = res;
	}
}

void ONO(){
	int n;
	while(cin >> n){
		if(n == 0) return;
		vector<int> primes;
		vector<int> is_prime(n + 1, 1);
		for(int i = 2; i <= n; i++){
			if(is_prime[i]){
				primes.push_back(i);
				for(long long j = (long long) i * i; j <= n; j += i){
					is_prime[j] = 0;
				}
			}
		}
		vector<pair<int, int>> fac = factor(primes, n);
		vector<long long> divs = {1LL};
		for(auto [p, exp] : fac){
			vector<long long> temp;
			for(auto d : divs){
				long long val = 1;
				for(long long i = 0; i <= exp; i++){
					temp.push_back(d * val);
					val *= p;
				}
			}
			divs = temp;
		}
		long long ans = 0;
		for(long long x : divs){
			if(x <= MX){
				ans += cnt[x];
				ans %= MOD;
			}
		}
		ps(ans);
	}

}

int main(){
	cpu();
	int t = 1;
	pre();
	//cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
