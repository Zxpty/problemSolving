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
const long long mod = 1e9+7;

void solve(){

  int n; cin>>n;
  long long mn = mod;
  long long mn2 = mod;
  long long ans  = 0;
  for(int i=0;i<n;i++){
    int m; cin>>m;
    vector<long long> p(m);
    read(p);
    sort(p.begin(),p.end());
    mn = min(mn,p[0]);
	if(m != 1) mn2 = min(mn2,p[1]);
	else mn2 = 0;
	if(m != 1) ans+= p[1];
  }
  cout<< ans - mn2 + mn << '\n';
  

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

