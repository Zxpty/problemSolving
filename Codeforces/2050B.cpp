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
vi r(n);
read(r);
ll sum = 0;
for(int x : r)sum+=1LL*x;
if(sum%n!=0){
  cout<<"NO\n";
  return;
}
ll pares = 0;
ll sum_pares = 0;
for(int i = 0; i<n; i+=2){
  sum_pares+=1LL*r[i];
  pares++;
}
ll impares = 0;
ll sum_impares = 0;
for(int i = 1; i<n; i+=2){
  sum_impares+=1LL*r[i];
  impares++;
}

if(sum_pares%pares==0 && sum_impares%impares==0 && sum_pares/pares==sum_impares/impares){
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

