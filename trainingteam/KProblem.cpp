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
  ll n,p; cin>>n>>p;
  ll op = (n-p)/2;
  op%=p;
  if(op==0 || 2*op==p){
    cout<<"0\n";
    return;
  }
  cout<<op*2<<'\n';
  /*if(op%2==0){
    cout<<op<<'\n';
  }else{
    while((n-(p*piso))%2!=0){
      piso--;
    }
    cout<<n-(p*piso)<<'\n';
  }*/


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

