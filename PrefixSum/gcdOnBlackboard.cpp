#include <algorithm>
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
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

typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;

void solve(){
	int n; read(n);
	vector<int> r(n); read(r);
	vector<int> p(n),s(n);
	for(int i=1;i<n;i++){
		p[i] = __gcd(p[i-1],r[i-1]);
	}
	for(int i=n-1;i>=1;i--){
		s[i] = __gcd(s[i+1],r[i]);
	}
	int ans = s[0];
	for(int i=1;i<=n;i++){
		ans = max(ans,__gcd(p[i-1],s[i]));
		dbg(p[i-1]);
		dbg(s[i]);
		dbg(__gcd(p[i-1],s[i]));
	}
	cout<<ans;
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
