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
  vector<int> r(n);
  for(int& x : r) cin>>x;
  sort(r.begin(),r.end());
  auto isPrime = [&](int n){
    if(n <= 1 || n % 2 == 0) return false;
    if(n == 2) return true;
    for(int i=3;i*i<=n;i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  };
      int i = n-1;
  int game = 0;
  while(i>=0 && isPrime(r[i])==false){
    game++;
    i--;
  }
  if(game%2!=0){
    cout<<"Alice";
  }else{
    cout<<"Bob";
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


