#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
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

typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;

void solve(){

  int n; read(n);
  vector<pair<pair<int,int>,int>> q(n);
  for(int i=0;i<n;i++){
		int l,r; read(l,r);
    q[i] = {{l,r},i};
  }
  sort(q.begin(),q.end(),[](const auto& a, const auto& b){
    return a.first.first<b.first.first || (a.first.first == b.first.first && a.first.second<b.first.second);
  });
  set<int> st;
  vector<int> ans(n,0);
  map<int,int> freq;
  for(auto x : q){
    int l = x.first.first;
    int r = x.first.second;
    for(int i=l;i<=r;i++){
      freq[i]++;
    }
  }
  for(auto x : q){
    int l = x.first.first;
    int r = x.first.second;
    int i = x.second;
    dbg(l);
    dbg(r);
    dbg(i);
    if(l==r){

    }
    for(int j = l; j<=r;j++){
      dbg(j);
      if(st.find(j)==st.end() && freq[j]==1){
        st.insert(j);
        ans[i] = 1;
        break;
      }
    }
    dbg(st);
  }
}

int main()
{
    cpu();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

