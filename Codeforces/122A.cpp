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
typedef vector<int> vi;
const ll mod = 1e9+7;
void solve()
{
  auto check = [&](int &x){
    string s = to_string(x);
    map<int,int> mp;
    int n = s.size();
    for(int x : s) mp[x-'0']++;
    dbg(mp);
    if(mp[7]+mp[4]==n)return true;
    return false;
  };
  int n; cin>>n;
  if(check(n)){
    cout<<"YES\n";
  }else{
    dbg(n/4);
    dbg(n/7);
      dbg(n%4);
      dbg(n%7);
    if(n%4==0 || n%7==0 || n%47==0 || n%744==0){
      
      cout<<"YES\n";
    }else cout<<"NO\n";
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

