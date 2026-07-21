#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define sz(a) ((int)(a).size())
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

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


typedef int64_t i64;
const long long MX = 1e9+7;

template<typename T>
struct sparse_table{
	int N;
	int levels;
	// table[i][j] = q(i, i + 2^j - 1)
	// table[i][j] = intervalo empezando en i con longitud 2^j
	vector<vector<T>> table;

	sparse_table(vector<T>& A){
		N = (int) A.size();
		levels = ceil(log2(N)) + 1;
		table = vector<vector<T>> (N, vector<T>(levels));
		build(A);
	}

	auto& operator[](size_t i) { return table[i]; }

	int highest_bit(unsigned x){ return x == 0 ? -1 : 31 - __builtin_clz(x); };

	T op(T& a, T& b){ return min(a, b); }

	void build(vector<T>& A){
		for(int i = 0; i < N; i++) table[i][0] = A[i];

		for(int alpha = 1; alpha < levels; alpha++){
			for(int i = 0; i < N; i++){
				int j = i + (1 << (alpha - 1));
				if(j < N){
					table[i][alpha] = op(table[i][alpha - 1], table[j][alpha - 1]);
				}
			}
		}
	}
	
	// O(logN) (Sin superposicion de intervalos)
	T query(int l, int r){
		T ans = 0; // Check
		for(int bit = levels - 1; bit >= 0; bit--){
			if(l + (1 << bit) - 1 <= r){
				ans = op(ans, table[l][bit]);
				l += (1 << bit);
			}
		}
		return ans;
	}

	// O(1) (Con superposicion de intervalos)
	T query_over(int l, int r){
		int high = highest_bit(r - l + 1);
		return op(table[l][high], table[r - (1 << high) + 1][high]);
	}
};

void GA(){
	int n; read(n);
	vector<pair<int, int>> intervals(n);
	vector<int> s;
	for(int i = 0; i < n; i++){
		int left, right; read(left, right);
		intervals[i] = {left, right};
		s.push_back(left);
		s.push_back(right);
		s.push_back(right + 1);
	}

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	auto get = [&](int x){
		return lower_bound(s.begin(), s.end(), x) - s.begin();
	};
	
	for(auto &[l, r] : intervals){
		l = get(l);
		r = get(r);
	}

	vector<int> diff(int(s.size()) + 1);
	for(auto [l, r] : intervals){
		diff[l]++;
		diff[r + 1]--;
	}

	for(int i = 1 ; i < int(s.size()); i++){
		diff[i] += diff[i - 1];
	}

	sparse_table<int> st(diff);
	for(int i = 0; i < n; i++){
		int l = intervals[i].first;
		int r = intervals[i].second;
		//dbg(l, r);

		if(st.query_over(l, r) >= 2){
			ps(i + 1);
			return;
		}
	}
	ps(-1);

}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}
