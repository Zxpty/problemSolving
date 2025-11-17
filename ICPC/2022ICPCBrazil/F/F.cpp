#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define sz(a) ((int)(a).size())
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

void ps() {cout << "\n";}
template <class T> void ps(const T &x) {cout << x << "\n";}
template <class T> void ps(vector<T> &v) {for(auto& x : v) cout << x << ' '; cout << "\n";}

typedef int64_t i64;
const int MX = 1e5;

void GA(){
    int n, m; read(n, m);
    vector<string> r(n); read(r);
    map<string, int> mp;

    for(char a = 'a'; a <= 'z'; a++){
        for(auto t : r){
            string res = t;
            for(int i = 0; i < (int)res.size(); i++){
                if(res[i] == '*'){
                    res[i] = a;
                }
            }
            mp[res]++;
        }
    }

    vector<pair<string, int>> ans(mp.begin(), mp.end());
	sort(ans.begin(), ans.end(), [&](auto a, auto b){
			if(a.second != b.second) return a.second > b.second;
			return a.first < b.first;
			}); 
    cout << ans[0].first << " " << ans[0].second << "\n";
}

int main(){
    cpu();
    int t = 1;
    //cin >> t;
    while (t--){
        GA();
    }
    return 0;
}

