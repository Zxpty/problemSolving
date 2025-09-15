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
  auto check  = [&](vi r){
    for(int i=1; i<n; i++){
      if(r[i-1]>r[i])
        return false;
    }return true;
  };
  int i  = 0, j = 0;
  while(i<n){
    if(r[i]<0){
      r[j]*= -1;
      j++;
      r[i]*=-1;
    }
    i++;
  }
  dbg(r);
  if(check(r)){
    cout<<"YES\n";
  }else cout<<"NO\n";

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

