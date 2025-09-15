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


typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vii;
typedef int64_t i64;
const ll MX = 1e9+7;

void GA(){
	int n, m, target; read(n, m, target);
	vector<string> r(n); read(r);
	int q = 0;
	for(int i = 0; i < n; i++){
		q+= count(r[i].begin(), r[i].end(), 'P');
	}
	string tx = r[target - 1];
	vector<pair<string, int>> rank(n);
	for(int i =0 ; i < n; i++){
		rank[i].first = r[i];
		rank[i].second = i + 1;
	}
	int qu = q;
	cin.ignore();
	vector<string> querys;
	while(q--){
		string s; getline(cin, s);
		querys.push_back(s);
	}
	auto check = [&](auto ax, auto bx){
		int cna = 0, cnb = 0;
		string a = ax.first;
		string b= bx.first;
		for(int i = 0; i < m;i++){
			if(a[i]== 'P') cna+= i + 1;
			if(b[i] == 'P') cnb+= i + 1;
		}
		return cna < cnb;
	};
	sort(rank.begin(), rank.end(), check);
	int idx = 0;
	for(int i = 0; i < n; i++){
		string s = rank[i].first;
		int cnP = count(s.begin(), s.end(), 'P');
		int cn = 0;
		while(true){
			string q = querys[idx];
			int cnY = count(q.begin(), q.end(), 'Y');
			if(cnY == 0){idx++; continue;}
				rank[i].second+= cnY - 3;
				for(int j = 0; j < n; j++){
					if(i != j && rank[j].second < rank[i].second){
						rank[j].second++;
					}
				}
				cn++;
				idx++;
			if(cn == cnP){
				break;
			}
		}
		cn = 0;
	}
	dbg(rank);
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
