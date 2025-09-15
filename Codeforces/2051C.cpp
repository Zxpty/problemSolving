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

  int n,m,k; cin>>n>>m>>k; 
  // n  = numero de preguntas diferentes, m = numero de listas diferentes
  // k = numero de preguntas que sabe la respuesta.
  vi a(m); read(a);
  unordered_set<int> q;
  for(int i=0;i<k;i++){
    int num; cin>>num;
    q.insert(num);
  }

  if(n>m){
    for(int i=0;i<m;i++){
      cout<<"0";
    }cout<<'\n';
    return;
  }

  string ans  = "";
  /*for(int i=0;i<m;i++){
    bool ok = 1;
    for(int j=0;j<n;j++){
      if(j+1==a[i])continue;
      if(!q.count(j+1)){
        ok = 0;
        break;
      }
    }
    ans+=(ok ? "1" : "0");
  }*/

  int cn = n-k;
  for(int i=0;i<m;i++){
    bool ok  = !q.count(a[i]);
    if(ok && cn>1){
      ans+="0";
    }else if(!ok && cn>0){
      ans+="0";
    }else ans+="1";
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

