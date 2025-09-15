#include <algorithm>
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
  vi r(n); read(r);
  dbg(r);
  auto fx = [&](int a, int b, int c){
    return a+b>c && b+c>a && c+a>b;
  };
  auto check = [&](vi &a, int l, int r){
    if(l == r) return true;
    int mn = *min_element(a.begin()+l,a.begin()+r+1);
    int mx = *max_element(a.begin()+l,a.begin()+r+1);
    return fx(mn,mn,mx);
  };
  for(int i=0;i<n-1;i++){
    if(check(r,i,i+1)){
      cout<<"YES\n";
      return;
    }
  }
  cout<<"NO\n";

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

