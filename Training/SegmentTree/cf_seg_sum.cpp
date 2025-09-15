#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

typedef int64_t i64;
const long long MX = 1e9+7;

struct seg{
    int size;
    vector<long long> ans;
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        ans.assign(2 * size, 0LL);
    }
    void build(vector<int>& a, int node, int left, int right){
        if(right - left == 1){
            if(left < a.size()){
                ans[node] = a[left];
            }
            return;
        }
        int m = (left + right) >> 1;
        build(a, 2 * node + 1, left, m);
        build(a, 2 * node + 2, m, right);
        ans[node] = ans[2 * node + 1] + ans[2 * node + 2];
    }
    void build(vector<int>& a){
        build(a, 0, 0, size);
    }
    void set(int pos, int val, int node, int left, int right){
        if(right - left == 1){
            ans[node] = val;
            return;
        }
        int m = (left + right) >> 1;
        if(pos < m){
            set(pos, val, 2 * node + 1, left, m);
        } else {
            set(pos, val, 2 * node + 2, m, right);
        }
        ans[node] = ans[2 * node + 1] + ans[2 * node + 2];
    }
    void set(int pos, int val){
        set(pos, val, 0, 0, size);
    }
    long long sum(int l, int r, int node, int left, int right){
		if(left >= r || right <= l) return 0LL;
        if(left >= l && right <= r) return ans[node];
        int m = (left + right) >> 1;
        long long leftSum = sum(l, r, 2 * node + 1, left, m);
        long long rightSum = sum(l, r, 2 * node + 2, m, right);
        return leftSum + rightSum;
    }
    long long sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};

void GA(){
    int n, m; read(n, m);
    seg st;
    st.init(n);
    vector<int> r(n); read(r);
    st.build(r);
    while(m--){
        int type; read(type);
        if(type == 1){
            int pos, val; read(pos, val);
            st.set(pos, val);
        }else{
            int l, r; read(l, r);
            cout << st.sum(l, r) << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        GA();
    }
    return 0;
}
