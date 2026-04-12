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
	int n, k, p, m; read(n, k, p, m);
	deque<pair<int, int>> dq;
	for(int i = 0; i < n; i++){
		int x; read(x);
		dq.push_back({x, i == p - 1});
	}
	int target = m;
	int ans = 0;

	while(true){
		int limit = min(k, n);
		int win_pos = -1;
		int best_pos = -1;
		int best_cost = MX;

		for(int i = 0; i < limit; i++){
			if(dq[i].second){
				win_pos = i;
			}
			if(dq[i].first < best_cost){
				best_cost = dq[i].first;
				best_pos = i;
			}
		}

		int play_pos = -1;
		if(win_pos != -1 && dq[win_pos].first <= target){
			play_pos = win_pos;
			ans++;
		}else{
			if(best_cost > target) break;
			play_pos = best_pos;
		}
		target -= dq[play_pos].first;
		auto deleted_card = dq[play_pos];
		dq.erase(dq.begin() + play_pos);
		dq.push_back(deleted_card);
	}
	ps(ans);

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
