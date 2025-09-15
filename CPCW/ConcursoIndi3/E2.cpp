#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
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

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.ff, ", ", x.ss, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.ff, ' ', x.ss); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}


typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vii;
typedef int64_t i64;
const ll MX = 2e18+7;

void GA() {
	set<long long> st = {0};
    map<long long, long long> mp;
	long long mn = 1;
    int q; read(q);
    while(q--) {
        char op; read(op);
        long long num; read(num);
        if (op == '+') {
			st.insert(num);
			if(num == mn){
				while(st.find(mn) != st.end()) mn+=num;
			}
			for(auto it = mp.begin(); it != mp.end();){
				if(num == it->second){
					it = mp.erase(it);
				}else it++;
			}
		} else {
			if(num == 1){
				ps(mn);
				continue;
			}
			if (mp.find(num) != mp.end()) {
                ps(mp[num]);
                continue;
            }
			long long ans = 0;
			while(true){
				long long check = ans * num;
				if(st.find(check) == st.end()){
					mp[num] = check;
					ps(check);
					break;
				}
				ans++;
			}
        }
    }
}

int main(){
	cpu();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

