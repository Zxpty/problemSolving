#include <bits/stdc++.h>
#ifdef LOCAL
#include "../../debug.cpp"
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

int f91(int n){
  if(n<=100) return f91(f91(n+11));
  return n-10;
}

void solve(int n){

  cout<<"f91("<<n<<") = "<<f91(n)<<'\n';
}

int main()
{
    cpu();
    int t = 1;
    int n;
    while (cin>>n && n>0)
    {
        solve(n);
    }
    return 0;
}

