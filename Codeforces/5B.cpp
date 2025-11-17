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

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.first, p.second);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.first, ", ", x.second, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.first, ' ', x.second); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}


const int MX = 1e9;

void ONO(){
    string s;
    vector<string> r;
	while(getline(cin, s)){
        r.push_back(s);
    }
    int mx = 0;
    for(auto x : r){
        mx = max(mx, int(x.size()));
        //cout << x.size() << " " << x << '\n';
    }
    int n = int(r.size()) + 2;
    int m = mx + 2;
    vector<vector<char>> ans(n, vector<char>(m,' '));
    for(int i = 0; i < m; i++){
        ans[0][i] = '*';
    }
    for(int i = 0; i < m; i++){
        ans[n - 1][i] = '*';
    }
    for(int i = 0; i < n; i++){
        ans[i][0] = '*';
    }
    for(int i = 0; i < n; i++){
        ans[i][m - 1] = '*';
    }
    int fila = 1;
    bool ok = 0;
    for(auto t : r){
        int ga = int(t.size());
        int diff = mx - ga;
        if(diff % 2 == 0){
            diff /= 2;
        }else{
            if(ok){
                diff = (diff + 1) / 2;
                ok = 0;
            }else{
                diff = (diff - 1) / 2;
                ok = 1;
            }
        }
        for(int i = 0; i < ga; i++){
            ans[fila][1 + diff + i] = t[i];
        }
        fila++;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j];
        }
        ps();
    }
}

int main(){
	cpu();
	ONO();
	return 0;
}
