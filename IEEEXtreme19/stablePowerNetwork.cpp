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
const long long MX = 2e18;
using pii = pair<long long, long long>;
void GA(){
    int n,m; read(n,m);
    vector<vector<array<long long,3>>> adj(n+1);
    long long lo = LLONG_MAX, hi = 0;
    for(int i=0;i<m;i++){
        long long u,v,w,r; read(u,v,w,r);
        adj[u].push_back({v,w,r});
        adj[v].push_back({u,w,r});
        lo = min(lo, r);
        hi = max(hi, r);
    }

    auto dijkstra = [&](long long max_risk, long long &total_time){
        vector<long long> dist(n+1, LLONG_MAX);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        dist[1] = 0;
        pq.push({0,1});

        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d > dist[u]) continue;

            for(auto e : adj[u]){
                int v = e[0];
                long long w = e[1], r = e[2];
                if(r > max_risk) continue;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[n] == LLONG_MAX) return false;
        total_time = dist[n];
        return true;
    };

    long long ans_risk = -1, ans_time = -1;
    while(lo <= hi){
        long long mid = lo + (hi-lo)/2;
        long long t;
        if(dijkstra(mid, t)){
            ans_risk = mid;
            ans_time = t;
            hi = mid-1; 
        }else{
            lo = mid+1;
        }
    }

    if(ans_risk == -1) ps(-1);
    else ps(ans_risk, ans_time);
}


int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		GA();
	}
	return 0;
}

