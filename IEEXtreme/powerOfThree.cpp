#include <bits/stdc++.h>
#include <cmath>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int MX = 100;
vector<ll> precal;
void init(){
  ll current = 1;
  for(int i=0;i<=MX;i++){
    precal.push_back(current);
    current*=3;
  }
}

void solve()
{
  dbg(precal);
  auto ispower = [&](int n){
    return n>0 && 1162261467%n==0;
  };
  int n; cin>>n;
  if(ispower(n)){
    for(int i=0;i<=MX;i++){
      if(n==precal[i]){
        cout<<i;
        return;
      }
    }
  }else{
    cout<<"-1";
    return;
  }
}
int main()
{
    cpu();
    int t = 1;
    init();
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

