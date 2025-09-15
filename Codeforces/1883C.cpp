#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll mod = 1e9+7;
void solve()
{
  int n,k; cin>>n>>k;
  vi r(n);
  for(int& x : r) cin>>x;
  if(k==4){
    const int XD = 11;
    int cn = 0;
    int mn = 11;
    for(int i=0;i<n;i++){
      if(r[i]%k==0){
        cout<<"0\n";
        return;
      }
      mn = min(mn,k-(r[i]%k));
      if(r[i]%2==0)cn++;
    }
    if(cn>=2){
      cout<<"0\n";
    }else{
      if(cn==1){
        cout<<min(mn,1)<<'\n';
      }else cout<<min(mn,2)<<'\n';
    }
    }else{
    int mn = 11;
    for(int i=0;i<n;i++){
      if(r[i]%k==0){
        cout<<"0\n";
        return;
      }
      mn = min(mn, k-(r[i]%k));
    }
    cout<<mn<<'\n';
  }
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

