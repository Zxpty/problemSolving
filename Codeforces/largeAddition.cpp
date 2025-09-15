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
  string s; cin>>s;
  int n = (int)s.size();
  bool flag = true;
  for(int i=1;i<n-1;i++){
    if(s[i]=='0'){
      flag = 0;
      break;
    }
  }
  if(!flag){cout<<"NO\n";return;}
  cout<<((s[0]=='1' && s[n-1]!='9')?"YES" : "NO")<<'\n';
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

