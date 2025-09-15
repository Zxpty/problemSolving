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
	int n, m, r; read(n, m, r);
	int cntP = 0;
  vector<pair<int, string>> v(n); // equipos
  for (int i = 0; i < n; i++) {
    v[i].first = i;
    cin >> v[i].second;
    for (char ch : v[i].second) {
      if (ch == 'P') cntP++;
    }
  }

  cin.ignore();
  vector<string> reacts(cntP);
  for (int i = 0; i < cntP; i++) {
    string s; getline(cin, s);
    reacts[i] = s;
  }
  //dbg(reacts, v, cntP);

  vector<pair<pair<int, string>, int>> movs;
  int currP = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (v[j].second[i] == 'P') {
        int puestos = 0;
        if (reacts[currP][13] == 'w' || reacts[currP].size() <= 18) puestos = 0;
        else puestos = reacts[currP].size() - 19;
        movs.push_back({{ j, v[j].second }, puestos});
        currP++;
      }
    }
  }

  //dbg(movs);

  for (auto [buscar, puestos] : movs) {
    int idx;
    for (int i = 0; i < n; i++) {
      if (v[i] == buscar) {
        idx = i;
        break;
      }
    }
    //dbg(idx, puestos, buscar, v);
    if (idx - puestos < 0) puestos = idx;
    for (int i = idx; i > idx - puestos; i--) {
      swap(v[i], v[i-1]);
    }
  }
  //dbg(v);

  for (int i = 0; i < n; i++) {
    if (v[i].first == r-1) {
      cout << i+1;
      return;
    }
  }
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
