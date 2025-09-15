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
	int n, k; read(n,k);
	map<ll,int> mp;
	for(int i=0;i<n;i++){
		int num; cin>>num;
		mp[num]++;
	}
	ll ans = 0;
	ll total = n;
	ll last = 0;
	for(auto [x,freq] : mp){
		if(k > total * (x - last)){
			ans+=total*(x-last);
			k-=total*(x-last);
			total-=freq;
			ans+=freq;
			last = x;
		}else{ ans+=k; break; }
	}
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


