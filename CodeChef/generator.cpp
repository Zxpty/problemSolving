#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
#else
#define dbg(...)
#endif

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

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <class T> void ckmax(T &a, const T &b) { a = max(a, b); }

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

mt19937_64 rng((long long) chrono::steady_clock::now().time_since_epoch().count());

int _myrandomint(int x) { return rng() % x; }
long long _myrandomlong(long long x) { return rng() % x; }

int gint(int mn, int mx){
	assert(mn <= mx);
	return rng() % (mx - mn + 1) + mn;
}

long long glong(long long mn, long long mx){
	assert(mn <= mx);
	return rng() % (mx - mn + 1) + mn;
}

char gchar(char mn = 'a', char mx = 'z'){
	assert(mn <= mx);
	int pmn = int(mn - 'a');
	int pmx = int(mx - 'a');
	assert(0 <= pmn && pmn < 26);
	assert(0 <= pmx && pmx < 26);

	int x = gint(pmn, pmx);
	char c = char('a' + x);
	return c;
}

string gstring(int max_size, char mn = 'a', char mx = 'z'){
	int size = gint(1, max_size);
	string ret = "";
	for(int i = 0; i < size; i++) ret += gchar(mn, mx);
	return ret;
}

vector<int> gpermutation(int size, int start = 1){
	vector<int> p(size);
	iota(p.begin(), p.end(), start);
	return p;
}

template <typename T>
void randomize(vector<T>& a){
	vector<int> order = gpermutation((int) a.size(), 0);
	random_shuffle(order.begin(), order.end(), _myrandomint);
	vector<T> b = a;
	for(int i = 0; i < (int) a.size(); i++) b[i] = a[order[i]];
	a.swap(b);
}

vector<int> gvectorint(int size, int mn = 0, int mx = 1000, bool diff = true){
    assert(size > 0);
    vector<int> a;
    if(mx < 1000){
        a = gpermutation(mx - mn + 1);
        randomize(a);
        for(int i = 0; i < (int) a.size(); i++){
            a[i] += mn - 1;
        }
    }

    if(!diff){
        a.resize(size);
        for(int i = 0; i < size; i++) a[i] = gint(mn, mx);
        return a;
    }

    assert(!a.empty());

    while(a.size() > size) a.pop_back();

    return a;
}
vector<long long> gvectorlong(int size, long long mn = 0, long long mx = 1000000000000LL){
	assert(size > 0);
	vector<long long> a(size);
	for(int i = 0; i < size; i++) a[i] = glong(mn, mx);
	return a;
}


vector<vector<int>> ggraph();

vector<vector<int>> gtree(int n){
	struct DSU{
		vector<int> p, size;
		DSU(int n = 1e5){
			p.resize(n + 1), size.resize(n + 1,1);
			for(int i = 1; i <= n; i++) p[i] = i;
		}

		int find(int x){
			if(p[x] != x) p[x] = find(p[x]);
			return p[x];
		}

		void merge(int x, int y){
			x = find(x), y = find(y);
			if(x == y) return;
			if(size[x] < size[y]) swap(x, y);
			size[x] += size[y];
			p[y] = x;
		}

		int get_size(int x) {return size[find(x)];}
	};
	vector<vector<int>> adj(n + 1);

	vector<pair<int, int>> alledges;
	for(int u = 1; u <= n; u++){
		for(int v = u + 1; v <= n; v++){
			alledges.push_back({u, v});
		}
	}
	randomize(alledges);

	DSU dsu(n);
	for(auto [u, v] : alledges){
		if(dsu.find(u) == dsu.find(v)) continue;
		dsu.merge(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	return adj;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<1<<'\n';
	int n = gint(2, 40);
	vector<int> a = gvectorint(n,1,80);
	randomize(a);
	ps(n);
	ps(a);
	
	
}

