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
const int MX = 100;

void solve(){
	int n; read(n);
	vi r(n); read(r);
	int start = r[0];
	int win = 0;
	for(int x=1;x<=MX;x++){
		int dis = abs(start-x);
		int min_dis = mod;
		for(int i=1;i<n;i++){
			int second_dis = abs(r[i]-x);
			min_dis = min(min_dis,second_dis);
		}
		if(dis<=min_dis)win++;
	}
	cout<<win<<'\n';
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


