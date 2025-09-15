#include <bits/stdc++.h>
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


void solve(){
	int n; read(n);
	vector<vector<int>> r(n - 1,vector<int>(n));
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n - 1; j++){
			read(r[j][i]);
		}
	}
	vector<vector<pair<int,int>>> q;
	for(int i = 0; i < n - 1; i++){
		map<int,int> freq;
		for(int j = 0; j < n; j++){
			freq[r[i][j]]++;
		}
		vector<pair<int,int>> p;
		for(auto x : freq){
			p.emplace_back(x.second, x.first);
		}
		sort(p.rbegin(), p.rend());
		q.push_back(p);
	}


	//dbg(q);
	vector<int> ans;
	set<int> st;
	int rep = 0;
	auto[freq, num] = q[0][0];
	auto[freq1, num1] = q[0][1];
	ans.push_back(num);
	ans.push_back(num1);
	st.insert(num);
	st.insert(num1);

	for(int i = 1; i < q.size(); i++){
		auto [freq, num] = q[i][0];
		auto [freq1, num1] = q[i][1];
		auto it = st.find(num);
		auto it2 = st.find(num1);
		if(it==st.end()){
			ans.push_back(num);
			st.insert(num);
		}
		if(it2 == st.end()){
			ans.push_back(num1);
			st.insert(num1);
		}

	}
	for(int i = 0; i < n; i++){
		cout<< ans[i] << ' ';
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
