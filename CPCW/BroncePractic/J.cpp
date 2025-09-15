#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) { cin >> x; }
template <class R, class... T> void read(R& r, T&... t) { read(r); read(t...); }
template <class T> void read(vector<T> &v) { for (auto& x : v) read(x); }
template <class F, class S> void read(pair<F, S> &p) { read(p.first, p.second); }
template <class T, size_t Z> void read(array<T, Z> &a) { for (auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) { cout << x; }
template <class R, class... T> void pr(const R& r, const T&... t) { pr(r); pr(t...); }
template <class F, class S> void pr(const pair<F, S> &x) { pr("{", x.first, ", ", x.second, "}\n"); }
void ps() { pr("\n"); }
template <class T> void ps(const T &x) { pr(x); ps(); }
template <class T> void ps(vector<T> &v) { for (auto& x : v) pr(x, ' '); ps(); }
template <class T, size_t Z> void ps(const array<T, Z> &a) { for (auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) { pr(x.first, ' ', x.second); ps(); }
template <class R, class... T> void ps(const R& r, const T &...t) { pr(r, ' '); ps(t...); }

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int, int>> vii;

const ll MX = 1e9 + 7;

void GA() {
    int m;
    read(m);
    int a, b;
    vector<pair<int, int>> r;
    while (cin >> a >> b && (a != 0 || b != 0)) {
        if (b > 0 && a < m) { 
            r.emplace_back(a, b);
        }
    }
    sort(r.begin(), r.end());
    int curr = 0;
    int i = 0;
    int n = r.size();
    vector<pair<int, int>> ans;
    while (curr < m && i < n) {
        int farthest_end = curr;
        int best_index = -1;
        while (i < n && r[i].first <= curr) {
            if (r[i].second > farthest_end) {
                farthest_end = r[i].second;
                best_index = i;
            }
            i++;
        }

        if (best_index == -1) {
            ps(0);
            return;
        }

        ans.push_back(r[best_index]);
        curr = farthest_end;
    }

    if (curr >= m) {
        ps((int)ans.size());
        for (auto x : ans) {
            cout << x.first << " " << x.second << '\n';
        }
    } else {
        ps(0);
    }
}

int main() {
    cpu();
    int t = 1;
    cin >> t;
    while (t--) {
        GA();
        if (t > 0) {
            ps();  
		}
    }
    return 0;
}
