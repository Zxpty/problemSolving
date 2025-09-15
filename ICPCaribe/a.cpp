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
  if(n<100 || n>100000){
    cout<<"NO SOLUTION";
    return;
  }
  
  // perfect-great-good-bad
  for(int p = 0;p<=100;p++){
    for(int g=0;g<=100-p;g++){
      for(int go=0;go<=100-p-g;go++){
        int bad = 100-p-g-go;
        int reach = 1000*p+100*g+10*go+1*bad;
        if(reach==n){
          cout<<"Perfect: "<<p<<"\n";
          cout<<"Great: "<<g<<'\n';
          cout<<"Good: "<<go<<'\n';
          cout<<"Bad: "<<bad<<'\n';
          return;
        }
      }
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


