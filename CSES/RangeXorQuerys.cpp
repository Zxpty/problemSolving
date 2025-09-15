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
void solve(){
    int n,q; cin>>n>>q;
    vector<ll> r(n);
    for(auto& x : r) cin>>x;
    vector<ll> preXor(n);
    preXor[0]=r[0];
    for(int i=1;i<n;i++){
      preXor[i] = preXor[i-1]^r[i];
    }
    auto XOR = [&](int l,int r){
      if(l==0) return preXor[r];
      return preXor[r]^preXor[l-1];
    };
    while(q--){
      int l,r; cin>>l>>r;
      l--,r--;
      cout<<XOR(l, r)<<'\n';
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


