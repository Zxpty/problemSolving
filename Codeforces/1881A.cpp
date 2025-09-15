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
  int n,m; cin>>n>>m;
  string a, b; cin>>a>>b;
  if(n==m && a==b){cout<<"0\n";return;}
  int cn  = 0;
  bool check = 0;
  int mv  = 0;
  while(!check){
    if(a.find(b) != string::npos){
      break;
    }
    a+=a;
    cn++;
    if(a.size()>b.size() && a.find(b)==string::npos && mv>5){
      cn = -1;
      break;
    }
    mv++;
  }

  cout<<cn<<'\n';

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

