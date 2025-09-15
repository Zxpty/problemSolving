#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
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
	string s; read(s);
	stack<int> st;
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(i&1){
			if(s[i] == '(')st.push(i);
			else{
				assert(!st.empty());
				int j = st.top(); st.pop();
				ans+= i - j;
			}
		}else{
			if((int)st.size()==0){
				st.push(i);
				s[i] = '(';
			}else{
				int j = st.top(); st.pop();
				ans+= i-j;
				s[i] = ')';
			}
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
