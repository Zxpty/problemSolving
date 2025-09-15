#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
void solve()
{
  stack<ll> pila;
  stack<ll> maxElements;
  int n; cin>>n;
  int op;
  while(n--){
    cin>>op;
    int mx = -1;
    if(op==1){
      ll x; cin>>x;
      pila.push(x);
      if(maxElements.empty() || x>=maxElements.top()){
        maxElements.push(x);
      }
    }else if(op==2){
      if(!pila.empty()){
        ll val = pila.top();
        pila.pop();
        if(!maxElements.empty() && val==maxElements.top()){
          maxElements.pop();
        }
      }
    }else if(op==3){
      if(!pila.empty() && !maxElements.empty()){
        cout<<maxElements.top()<<'\n';
      }
    }
  }
  dbg(pila);
}
int main()
{
    cpu();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


