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
void solve()
{
  ll n; cin>>n;
  vector<int> r;
  string x = to_string(n);
  for(int i=0;i<(int)x.size();i++){
    r.push_back(x[i]-'0');
  }
  reverse(r.begin(),r.end());
  int carry = 0;
  int cn = 0;
  int sum = 0;
  for(int i=0;i<r.size();i++){
    sum+=r[i];
    r[i] = r[i]-carry;
    if(r[i]==9 || i==(int)r.size()-1){
      carry = 0;
      continue;
    }
    cn++;
    carry = 1;
  }
  cout<<sum+9*cn<<'\n';
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

