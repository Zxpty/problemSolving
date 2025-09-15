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
  int sum = 0;
  for(int i=0;i<n;i++) sum+=r[i];
  if(sum%2==0){cout<<0<<'\n';return;}
  int ans = 1000;
  for(int i=0;i<n;i++){
    int curr = r[i]%2;
    int cn = 0;
    while(r[i]%2==curr){
      r[i]/=2;
      cn++;
    }
    ans = min(ans,cn);
  }
  cout<<ans<<'\n';
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

