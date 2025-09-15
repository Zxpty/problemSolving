#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
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
const ll mod = 1e9+7;

void solve(){
	int n, m; read(n, m);
	vector<vector<int>> r(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>r[i][j];
		}
		sort(r[i].begin(),r[i].end());
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	for(int i = 0; i < n; i++){
		pq.push({r[i][0], i});
	}
	vector<int> orden;
	int top_car = -1;
	bool ok = 1;
	for(int round = 0; round < m; round++){
		vector<pair<int,int>> sg_round;
		for(int i = 0; i < n; i++){
			auto [card, cow] = pq.top();
			pq.pop();
			if(card <= top_car){
				ok = 0;
				break;
			}
			top_car = card;
			orden.push_back(cow + 1);
			if(r[cow].size() > round + 1){
				pq.push({r[cow][round +1], cow});
			}
			if(!ok) break;
		}
	}
	if(!ok){
		ps(-1);
		return;
	}
	for(int i = 1; i < orden.size(); i++){
		if(orden[i] == orden[i - 1]){
			ps(-1);
			return;
		}
	}
	for(int i = 0; i < n; i++){
		cout<<orden[i] << ' ';
	}ps();
}

int main(){
	cpu();
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
