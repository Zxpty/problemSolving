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

vector<ll> A;
vector<int> P;
void solve()
{
  int n,q; cin>>n>>q;
  A.resize(n,0);
  P.resize(n);
  for(int i=0;i<n;i++){
    cin>>P[i];
    P[i]--;
  }
  while(q--){
    int op; cin>>op;
    int l,r,c;
    if(op==0){
      cin>>l>>r>>c;
      for(int i=l;i<=r;i++){
        A[i]+=c;
      }
    }else if(op==1){
      cin>>l>>r>>c;
      l--,r--;
      for(int i=l;i<=r;i++){
        A[P[i]]+=c;
      }
    }else if(op==2){
      cin>>l>>r;
      l--,r--;
      ll sum = 0;
      for(ll i=l;i<=r;i++){
        sum+=A[i];
      }
      cout<<sum<<'\n';
    }else if(op==3){
      cin>>l>>r;
      l--,r--;
      ll sum = 0;
      for(ll i=l;i<=r;i++){
        sum+=A[P[i]];
      }
      cout<<sum<<'\n';
    }
  }
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

