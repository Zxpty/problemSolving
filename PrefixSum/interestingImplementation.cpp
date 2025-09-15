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
	string s = "aczzx";
	map<char, char> mp = {{'a', 'z'}, {'b', 'y'}, {'c', 'x'}, {'d', 'w'},
                        	  {'e', 'v'}, {'f', 'u'}, {'g', 't'}, {'h', 's'},
                              {'i', 'r'}, {'j', 'q'}, {'k', 'p'}, {'l', 'o'},
                              {'m', 'n'}, {'n', 'm'}, {'o', 'l'}, {'p', 'k'},
                              {'q', 'j'}, {'r', 'i'}, {'s', 'h'}, {'t', 'g'},
                              {'u', 'f'}, {'v', 'e'}, {'w', 'd'}, {'x', 'c'},
                              {'y', 'b'}, {'z', 'a'}};
	int n = (int)s.size();
	map<char,stack<int>> pos;
	long long ans = 0;
	for(int i=0;i<n;i++){
		char curr = s[i];
		char inverse = mp[s[i]];
		if(!pos[inverse].empty()){
			int id = pos[inverse].top();
			pos[inverse].pop();
			ans+= i - id;
		}else{
			pos[curr].push(i);
		}
	}
	cout<<ans<<'\n';


}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
