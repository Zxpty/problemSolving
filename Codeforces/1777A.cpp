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
	vi r(n); read(r);
	vi ans;
	int left = 0;
	while(left<n){
		int right = left;
		int cn = 0;
		while(right<n && ((r[right]%2==0 && r[left]%2==0) ||(r[right]%2!=0 && r[left]%2!=0))){
			right++;
			cn++;
		}
		if(cn>=2){
			ans.push_back(cn);
		}
		left = right;
	}
	if(ans.empty()){cout<<0<<'\n'; return;}
	int result = 0;
	for(int x : ans){
		result+=x-1;
	}
	cout<<result<<'\n';
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
