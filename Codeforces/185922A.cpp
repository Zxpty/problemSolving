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
	bool ok = 1;
	for(int i=0;i+1<n;i++){
		if(r[i]!=r[i+1]) {ok = 0; break;}
	}
	if(ok){cout<<-1<<'\n';return;}
	int ones =  count(r.begin(),r.end(),1);
	if(ones>0){
		cout<<ones<<' '<<n-ones<<'\n';
		for(int i = 0; i<ones; i++) cout<<1<<' ';
		cout<<'\n';
		for(int i = 0; i<n; i++) {
			if(r[i]!=1)cout<<r[i]<<' ';
		}
		cout<<'\n';
	}else{
		int pares = 0, impares = 0;
		vi a,c;
		for(int i=0; i<n;i++){
			if(r[i]%2==0) {a.push_back(r[i]);pares++;}
			else {c.push_back(r[i]);impares++;}
		}
		if(pares>0 && impares > 0){
			cout<<impares<<' '<< pares<<'\n';
			for(int x : c) cout<<x<<' ';
			cout<<'\n';
			for(int x : a) cout<<x<<' ';
			cout<<'\n';
		}else if(pares==0 && impares>0){
			sort(c.begin(),c.end());
			int mn = c[0];
			int cn_mn = count(c.begin(),c.end(),mn);
			cout<<cn_mn<<' '<<impares-cn_mn<<'\n';
			for(int i=0;i<cn_mn;i++)cout<<mn<<' ';
			cout<<'\n';
			for(int i=0;i<impares;i++){
				if(c[i]!=mn)cout<<c[i]<<' ';
			}cout<<'\n';
		}else if(impares==0 && pares>0){
			sort(a.begin(),a.end());
			int mx = a[pares-1];
			int cn_mx = count(a.begin(),a.end(),mx);
			cout<<pares-cn_mx<<' '<<cn_mx<<'\n';
			for(int i=0;i<pares;i++){
				if(a[i]!=mx)cout<<a[i]<<' ';
			}cout<<'\n';
			for(int i=0;i<cn_mx;i++){
				cout<<mx<<' ';
			}cout<<'\n';
		}
	}
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


