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
typedef pair<int,int> pii;
const ll mod = 1e9+7;

void solve(){

  int n,x; cin>>n>>x;
  vi a(n),b(n);
  read(a);
  read(b);
  vector<pair<int,int>> r;
  for(int i=0;i<n;i++){
    r.push_back({a[i],b[i]});
  }  
  auto f  = [&](const pii& a, const pii& b){
    return (a.first*a.second)>(b.first*b.second);
  };
  sort(r.begin(),r.end(),f);
  int sum = 0;
  int coins = -1;
  for(int i=0;i<n;i++){
    sum+=(r[i].first*r[i].second);
    if(sum>=x){coins = i+1; break;}
  }
  cout<<coins<<'\n';
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

