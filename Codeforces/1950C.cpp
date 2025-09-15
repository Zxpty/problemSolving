#include <algorithm>
#include <bits/stdc++.h>
#include <string>
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
	string s; read(s);
	string hora = s.substr(0,2), min = s.substr(3,2);
	int int_hora = stoi(hora);
	int int_min = stoi(min);

	string ans = "";
	if(int_hora==0){
		ans = "12:"+min+" AM";
	}else if(int_hora ==12){
		ans = "12:"+min+" PM";
	}else if(int_hora<12){
		if(int_hora<10)ans+="0";
		ans+=to_string(int_hora)+":"+min+" AM";
	}else{
		int_hora-=12;
		if(int_hora<10)ans+="0";
		ans+=to_string(int_hora)+":"+min+" PM";
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
