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
	long long n; read(n);
	string s; read(s);
	vector<long long> pre(n);
	pre[0] = s[0] - '0';
	for(int i=1;i<n;i++){
		pre[i] = pre[i-1] + 1LL*(s[i]-'0');
	}
	long long ans = 0;
	map<long long,long long> mp;
	mp[0] = 1;
	for(int i=0;i<n;i++){
		long long diff = pre[i] - i - 1;
		ans+= mp[diff];
		mp[diff]++;
	}
	dbg(mp);
	cout<<ans<<'\n';
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
