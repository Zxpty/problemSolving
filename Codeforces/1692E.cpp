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
  int n,s; cin>>n>>s;
  vector<int> p(n);
  vector<int> r(2);
  vector<int> pre(n+1);
  
  for(int i=0;i<n;i++){
    cin>>p[i];
    r[p[i]]++;
  }
  pre[0] = p[0];
  for(int i=1;i<n;i++){
    pre[i] = pre[i-1]+p[i];
  }
  //dbg(pre);
  if(r[1]<s){
    cout<<"-1\n";
    return;
  }
 
  int mn = n;
  int le =0,ri=0;
  while(le<n ){
    int sum = 0;
    if((ri-1)>=0){
      sum+=pre[ri-1];
    }
    if((le-1)>=0){
      sum-=pre[le-1];
    }
    if(sum==s){
      mn = min(mn,le+n-ri);
      if(ri<n){
      ri++;
      }else{
        le++;
      }
    }else if(sum<s && ri<n){
      ri++;
    }else{
      le++;
    }
  }
  //dbg(le);
  //dbg(ri);
  cout<<mn<<'\n';
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


