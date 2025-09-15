#include <algorithm>
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
  int a,b,c; cin>>a>>b>>c;
  int diffA = abs(c-a);
  int diffB = abs(c-b);
  if(diffB>diffA){
    cout<<"Cat A\n";
  }else if(diffB<diffA){
    cout<<"Cat B\n";
  }else{
    cout<<"Mouse C\n";
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


