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
  int n; cin>>n;
  if(n<=4){
    cout<<-1<<'\n';
    return;
  }
  auto check = [&](int x ){
    if(x<=1)return false;
    for(int i=2;i*i<=x;i++){
      if(x%i==0)return false;
    }
    return true;
  };
  vector<int> imp;
  for(int i=1;i<=n;i+=2) imp.push_back(i);
  int l_imp = imp.back();
  vector<int> par;
  for(int i=2;i<=n;i+=2) par.push_back(i);
  bool ok = false;

  for(int i=0;i<(int)par.size();i++){
    if(!check(l_imp+par[i])){
      imp.push_back(par[i]);
      par.erase(par.begin()+i);
      ok = true;
      break;
    }
  }
  for(int x : par){
    imp.push_back(x);
  }
  for(int x : imp){
    cout<<x<<" ";
  }
  cout<<'\n';
  
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

