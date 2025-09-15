#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
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
  int n,H,M; cin>>n>>H>>M;
  vector<int> r(n); // hora y minuto en la que hace la tarea
  for(int i=0;i<n;i++){
    int hora,mn; cin>>hora>>mn;
    int res = (hora*60)+mn;
    r[i] = res;
  }
  int ans =(H*60+M);
  int mn = INT_MAX;
  for(int x : r){
    if((x-ans)<0){
      mn = min(mn, ((x-ans)+(24*60)));
    }else mn = min(mn,x-ans);
  }
  int horas = mn/60;
  int minutos = mn%60;
  cout<<horas<<" "<<minutos<<'\n';

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


