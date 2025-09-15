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
	vector<int> ans;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		ans.resize(2 * size, 1);
	}

	int op(int a, int b){
		return a + b;
	}
	void build(vector<int>& a, int node, int left, int right) {
        if(right - left == 1) {
            if(left < (int)a.size()) {
                ans[node] = a[left];
            }
            return;
        }
        int mid = (left + right) / 2;
        build(a, 2 * node + 1, left, mid);
        build(a, 2 * node + 2, mid, right);
        ans[node] = op(ans[2 * node + 1], ans[2 * node + 2]);
    }
		
	void build(vector<int>& a){
		build(a, 0, 0, size);
	}

	void modify(int pos, int val, int node, int left, int right) {
        if(right - left == 1) {
            ans[node] = val;
            return;
        }
        int mid = (left + right) / 2;
        if(pos < mid) modify(pos, val, 2 * node + 1, left, mid);
        else modify(pos, val, 2 * node + 2, mid, right);
        ans[node] = op(ans[2 * node + 1], ans[2 * node + 2]);
    }

	void modify(int pos, int val){
		modify(pos, val, 0, 0, size);
	}

	 int findKth(int k, int node, int left, int right) {
        if(right - left == 1) {
            return left;
        }
        int mid = (left + right) / 2;
        if(k < ans[2 * node + 1]) {
            return findKth(k, 2 * node + 1, left, mid);
        } else {
            return findKth(k - ans[2 * node + 1], 2 * node + 2, mid, right);
        }
    }
	int findKth(int k){
		return findKth(k, 0, 0, size);
	}
};


void GA(){
	int n; cin >> n;
    vector<int> r(n);
    for(int i = 0; i < n; i++) cin >> r[i];
    
    vector<int> posis(n);
    for(int i = 0; i < n; i++) cin >> posis[i];
    
    seg st;
    st.init(n);
    vector<int> initials(n, 1);
    st.build(initials);
	vector<int> ans;
	for(int i = 0; i < n; i++){
		int id = st.findKth(posis[i] - 1);
        ans.push_back(r[id]);
        st.modify(id, 0);
	}
	for(int x : ans) cout << x << " ";

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
