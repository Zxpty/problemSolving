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
  int a,b,c; cin>>a>>b>>c;
  int x,y,z; cin>>x>>y>>z;
  int dar = 0, nodar = 0;
  if(a>x && b>y && c>z){
    cout<<"Yes";
    return;
  }
  if(a>x){
    dar+= (a-x)/2;
  }else{
    nodar+= (x-a);
  }
  if(b>y){
    dar += (b-y)/2;
  }else{
    nodar +=(y-b);
  }
  if(c>z){
    dar += (c-z)/2;
  }else{
    nodar +=(z-c);
  }
  if(dar>=nodar){
    cout<<"Yes\n";
  }else cout<<"No\n";

 
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


