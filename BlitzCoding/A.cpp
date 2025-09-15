#include <bits/stdc++.h>
#include <string>
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

  ll a,b; read(a,b);
  vi r;
  for(int i=a;i<=b;i++){
    r.push_back(i);
  }
  auto check = [&](int x){
    string s = to_string(x);
    int n = (int)s.size();
    int cn4 = 0, cn7 = 0;
    for(int i=0;i<n;i++){
      if(s[i]=='4')cn4++;
      else if(s[i]=='7')cn7++;
    }
    return abs(cn4-cn7);
  };
  int ns = (int)r.size();
  int ans = 0;
  for(int i=0;i<ns;i++){
    ans+=check(r[i]);
  }
  cout<<ans<<endl;

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

