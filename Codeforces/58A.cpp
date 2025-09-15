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
  string x = "hello";
  int n = (int)s.size();
  int j = 0;
  for(int i=0;i<n;i++){
    if(s[i]==x[j])j++;
    if(j==5)break;
  }
  cout<<(j==5?"YES":"NO")<<'\n';

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

