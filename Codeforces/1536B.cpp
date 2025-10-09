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

void GA(){
	int n; read(n);
	string s; read(s);

	set<string> st;

	for(int i = 0; i < n - 1; i++){
		string one(1, s[i]);
		string two = one + s[i + 1];
		st.insert(one);
		st.insert(two);
	}

	st.insert(string(1, s[n - 1]));

	for(int i = 0; i < n - 2; i++){
		string three = s.substr(i, 3);
		st.insert(three);
	}

	auto check = [&](string ga){
		for(char c = 'a'; c <= 'z'; c++){
			string one(1, c);
			if(st.find(one) == st.end()){
				return one;
			}
		}
		for(char c = 'a'; c <= 'z'; c++){
			for(int d = 'a'; d <= 'z'; d++){
				string two(1, c);
				two += d;
				if(st.find(two) == st.end()){
					return two;
				}
			}
		}

		for(char c = 'a'; c <= 'z'; c++){
			for(char d = 'a'; d <= 'z'; d++){
				for(char e = 'a'; e <= 'z'; e++){
					string three(1, c);
					three += d;
					three += e;
					if(st.find(three) == st.end()){
						return three;
					}
				}
			}
		}
		string init = "aaaa";
		return init;
	};
	ps(check(s));
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
