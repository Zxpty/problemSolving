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
 string s; cin>>s;
 int lvl = 0;
 int vall = 0;
 for(char step : s){
   if(step =='U'){
     lvl++;
   }else{
     lvl--;
   }
   if(lvl==0 && step=='U'){
     vall++;
   }
 }
 cout<<vall;
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


