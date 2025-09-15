#include <algorithm>
#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.ff, ", ", x.ss, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.ff, ' ', x.ss); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}



typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;
template<typename T>
struct sparse_table{
	int N;
	int levels;
	vector<vector<T>> table;

	sparse_table(vector<T>& A){
		N = (int)A.size();
		levels = ceil(log2(N))+1;
		table = vector<vector<T>> (N,vector<T>(levels));
		build(A);
	}

	int highest_bit(unsigned x){ return x == 0 ? -1 : 31 - __builtin_clz(x); };
	auto& operator[](size_t i){return table[i];}

	T op(T& a, T& b){
		// aqui podemos utilizarlo para realizar nuestras operaciones
		return __gcd(a,b);
	}
	void build(vector<T>& A){
		// construimos nuestra tabla con info de acuerdo a lo que solicitemos
		for(int i = 0; i < N; i++) table[i][0] = A[i];
		for(int alpha = 1; alpha < levels; alpha++){
			for(int i = 0; i < N; i++){
				int j = i+(1 << (alpha - 1));
				if( j < N ){
					table[i][alpha] = op(table[i][alpha - 1],table[j][alpha - 1]);
				}
			}
		}
	}

	T query(int l, int r){
		T ans = 0;
		for(int bit = levels - 1; bit >= 0; bit--){
			if(l + (1 << bit) - 1 <= r){
				ans = op(ans,table[l][bit]);
				l+= (1 << bit);
			}
		}
		return ans;
	}
	T query_over(int l, int r){
		int high = highest_bit(r - l + 1);
		return op(table[l][high], table[r - (1 << high) + 1][high]);
	}
};
void solve(){
	int n; read(n);
	string s; read(s);
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			s[i] = '1';
		}else s[i] = '0';
	}
	ps(s);
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
