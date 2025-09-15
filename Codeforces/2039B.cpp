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
	string s; read(s);
	int n = (int)s.size();
	for(int i=0;i<n;i++){
		for(int j=1;j<=4;j++){
			if(i+j>n)continue;
			string x;
			for(int k = i;k<i+j;k++)x+=s[k];
			auto check = [&](string p){
				set<string> per;
				int le = (int)p.size();
				for(int i=0;i<le;i++){
					for(int j=1;j<=le;j++){
						if(i+j<=le) per.insert(p.substr(i,j));
					}
				}
				return (int)per.size();
			};
			if(check(x)%2==0){
				cout<<x<<'\n';
				return;
			}
			
		}
	}
	cout<<-1<<'\n';
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
