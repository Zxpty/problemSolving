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
typedef vector<int> vi;
const ll mod = 1e9+7;
void solve()
{
  int k; cin>>k;
  vi r(k);
  map<int,int> mp;
  for(int& x : r){
    cin>>x;
    mp[x]++;
  }
  for(int n : r){
    if((k-2)%n!=0)continue;
    int m = (k-2)/n;
    if(mp[n]>0 && mp[m]>0){
      if((n!=m)|| (mp[n]>1)){
        cout<<n<<" "<<m<<'\n';
        return;
      }
    }
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

