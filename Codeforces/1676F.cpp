#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);}
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
    int n, k; read(n, k);
    vector<int> r(n); read(r);
    sort(r.begin(), r.end());

    vector<pair<int, int>> p;
    int left = 0;
    while(left < n){
        int right = left;
        while(right < n && r[right] == r[left]) right++;
        p.emplace_back(r[left], right - left);
        left = right;
    }

    int m = int(p.size());
    int ll = -1, rr = -1;
    int curL = -1;

    for(int i = 0; i < m; i++){
        if(p[i].second >= k){
            if(curL == -1) {
                curL = i;
            }
            else if(p[i].first != p[i-1].first + 1){
                int l = p[curL].first;
                int r = p[i-1].first;
                if(ll == -1 || r - l > rr - ll){
                    ll = l;
                    rr = r;
                }
                curL = i;
            }
        }else{
            if(curL != -1){
                int l = p[curL].first;
                int r = p[i-1].first;
                if(ll == -1 || r - l > rr - ll){
                    ll = l;
                    rr = r;
                }
                curL = -1;
            }
        }
    }
    if(curL != -1){
        int l = p[curL].first;
        int r = p.back().first;
        if(ll == -1 || r - l > rr - ll){
            ll = l;
            rr = r;
        }
    }

    if(ll == -1) ps(-1);
    else ps(ll, rr);
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		ONO();
	}
	return 0;
}
