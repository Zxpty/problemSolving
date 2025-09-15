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
  int n; cin>>n;
  ll people = 0, bus_space = 0;
  for(int i=0;i<n;i++){
    char op;
    int num;
    cin>>op>>num;
    bool ok = false;
    if(op=='P'){
      people+=num;
    }else if(op=='B'){
      bus_space+=num;
      if(people+1<=bus_space){
        cout<<"YES\n";
        ok = true;
      }else cout<<"NO\n";
    }
    if(ok) {people=0,bus_space=0;};
    //dbg(i);
    //dbg(people);
    //dbg(bus_space);
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

