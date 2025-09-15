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
  string s; cin>>s;
  string y = s;
  sort(y.begin(),y.end());
  char first = y[0];
  reverse(s.begin(),s.end());
  int pos = 0;
  for(int i=0;i<(s.size());i++){
    if(s[i]==first){
      pos = i+1;
      break;
    }
  }
  cout<<(int)(s.size())-pos<<'\n';
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

