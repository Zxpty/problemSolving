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
typedef pair<int,int> pii ;
typedef vector<int> vi;
const ll mod = 1e9+7;

void solve(){

int n,x; read(n),read(x);
vector<int> a(n),b(n);
read(a);read(b);

vector<pii> r(n);
for(int i=0;i<n;i++){
  r[i].first = a[i];
  r[i].second = b[i];
}

auto f = [&](const pii& a, const pii& b){
  return a.first>b.first;
};
sort(r.begin(),r.end(),f);
dbg(r);
int remain = x;
int coins = 0;
for(auto p : r){
  if(remain<=0)break;
  int mxCoins = remain/p.first;
  mxCoins = min(mxCoins,p.second);
  if(mxCoins>0){
    remain -= mxCoins*p.first;
    coins++;
  }
}
if(remain>0){
  cout<<-1<<'\n';
}else cout<<coins<<'\n';


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

