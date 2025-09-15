#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
	vector<long long> r(n); read(r);
	long long sum = accumulate(r.begin(),r.end(),0LL);
	sort(r.begin(),r.end());

	long long left = 0, right = 1e18;
	long long ans = -1;
	while(left<=right){
		long long mid  = (left+right)/2;
		long double avr = (long double)(sum+mid)/(2.0*n);
		vector<long long> temp = r;
		temp[n-1]+=mid;
		int cn = lower_bound(temp.begin(),temp.end(),avr) - temp.begin();
		
		if(cn>n/2){
			ans = mid;
			right = mid - 1;
		}else{
			left = mid + 1;
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
