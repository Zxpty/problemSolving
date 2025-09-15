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
  int k,n; cin>>k>>n;
  if((n+1)/2<k || n>3*k){
    cout<<'*'<<'\n';
    return;
  }
  if(n<3*k){

  }else if(n==3*k){
    string s;
    for(int i=0;i<n;i++){

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

