#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>

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

void GA(){
	int n, m; read(n, m);
	vector<string> r(n); read(r);
	vector vis(n, vector(m, false));
	pair<int, int> start, end;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(r[i][j] == 'A'){
				start.first = i, start.second = j;
			}
			if(r[i][j] == 'B')
				end.first = i, end.second = j;
		}
	}
	vector<pair<int, int>> coords = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	auto valid = [&](int x, int y){
		return x >= 0 && x < n && y >=0 && y < m && !vis[x][y] && r[x][y] != '#';
	};
	map<pair<int,int>, char> mp = {{{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, 1} ,'R'}, {{0, -1}, 'L'}};
	vector<vector<pair<int, int>>> parent(n, vector<pair<int ,int>>(m, {-1, -1}));
	queue<pair<int, int>> q;
	q.push({start.first, start.second});
	vis[start.first][start.second] = 1;
	bool ok = 0;
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();
		if(make_pair(x, y) == end){
			ok = 1;
			break;
		}
		for(auto[rx, ry] : coords){
			int new_x = x + rx;
			int new_y = y + ry;
			if(valid(new_x, new_y)){
				parent[new_x][new_y] = {x, y};
				q.push({new_x, new_y});
				vis[new_x][new_y] = 1;
			}
		}
	}
	if(!ok){
		ps("NO");
		return;
	}
	string s;
	pair<int, int> curr = end;
	while(curr != start){
		auto[px, py] = parent[curr.first][curr.second];
		pair<int, int> move = {curr.first - px, curr.second - py};
		s+=mp[move];
		curr = {px, py};
	}
	reverse(all(s));
	ps("YES");
	ps((int) s.size());
	ps(s);
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
