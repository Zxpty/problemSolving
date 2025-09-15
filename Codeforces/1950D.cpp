#include <bits/stdc++.h>
#include <string>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
vector<int> r;
const int MX = 1e5+1;
vector<bool> dp (MX,false);
void init(){
  for(int i=1;i<=32;i++){
    int op = i;
    string p = "";
    while(op>0){
      int x = op%2;
      op/=2;
      p+=to_string(x);
    }
    reverse(p.begin(),p.end());
    r.push_back(stoi(p));
  }

  dp[0] = true;
  dp[1] = true;
  for(int i=2;i<MX;i++){
    for(int coins : r){
      if(i%coins==0 && dp[i/coins]){ // dp[i/coins] 121/11 = true , dp[i] = 121 -> true  || 3/7 = 0
        dp[i] = true;
      }
    }
  }
}

void solve()
{
  int num; cin>>num;
  if(dp[num]) cout<<"YES\n";
  else cout<<"NO\n";
}
int main()
{
    cpu();
    int t = 1;
    init();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


