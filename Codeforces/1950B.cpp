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
  int n; cin>>n;
  string s = "";
  for(int i=0;i<2*n;i++){
    for(int j=0;j<2*n;j++){
      if((i/2+j/2)%2==0){
        cout<<"#";
      }else{
        cout<<".";
      }
    }
    cout<<'\n';
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


