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
  int n, d; read(n,d);
  vector<int> ans = {1};
  if(d%3==0 || n>=3){
    ans.push_back(3);
  }
  if(d%5==0){
    ans.push_back(5);
  }
  if(d==9 ||(d%3==0 && n>=3) || n>=6){
    ans.push_back(9);
  }
  if(d==7 || n>=3){
    ans.push_back(7);
  }
  sort(ans.begin(),ans.end());
  for(int x : ans){
    cout<<x<<' ';
  }cout<<'\n';
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

