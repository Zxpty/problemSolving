#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
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
  vi r(n);
  for(int& x : r) cin>>x;
  if(n==1){
    cout<<-1<<'\n';
    return;
  }
  vector<int> rep(n,0);
  iota(rep.begin(),rep.end(),1);
  for(int i=0;i<n-1;i++){
      if(r[i]==rep[i]){
        swap(rep[i],rep[i+1]);
      }
  }
  if(r.back()==rep.back())swap(rep[n-1],rep[n-2]);
  for(int x : rep) cout<<x<<' ';
  cout<<'\n';
  /*bool ok = true;
  for(int i=0;i<n;i++){
      if(r[i]!=i+1){
        ok = false;
        break;
      }
  }
  if(ok){
    for(int i=0;i+1<n;i++){
      swap(r[i],r[i+1]);
    }
    for(int x : r){
      cout<<x<<' ';
    }
    cout<<'\n';
    return;
  }
  sort(r.begin(),r.end());
  for(int i=0;i<rep.size();i++){
    //dbg(rep[i]-1);
    //dbg(rep[i]-2);
      swap(r[rep[i]-1],r[rep[i]-2]);
  }
  for(int x : r){
    cout<<x<<' ';
  }
  cout<<'\n';
  
  //dbg(r);
  //dbg(rep);*/
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

