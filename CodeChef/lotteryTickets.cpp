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
const int MX = 1e6 + 10;
const int RIGHT = 100;
void solve(){
	int n; read(n);
	vi r(n); read(r);
	
	int start = r[0];
	int mx_start = *max_element(r.begin(),r.end());
	int mn = 0;
	int mx = MX;
	for(int i=1;i<n;i++){
		if(r[i]<=r[0]){
			mn = max(mn,r[i]);
		}
		if(r[i]>=r[0]){
			mx = min(mx,r[i]);
		}
	}
	int ans = 0;
	if(mx_start == start){
		ans = RIGHT - ((start+mn+1)/2)+1;
	}else{
		if(mn != 0){
			ans = start-((start+mn+1)/2) + (((start+mx)/2)-start+1);
		}else{
			ans = start-1 +(((start+mx)/2)-start+1);
		}
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


