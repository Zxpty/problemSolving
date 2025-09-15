#include <bits/stdc++.h>
#include <cmath>
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
  int n1,n2,n3; cin>>n1>>n2>>n3;
  queue<int>p1,p2,p3;
  int s1=0,s2=0,s3=0;

  while(n1--){
    int x; cin>>x;
    s1+=x;
    p1.push(x);
  }
  while(n2--){
    int x; cin>>x;
    s2+=x;
    p2.push(x);
  }
  while(n3--){
    int x; cin>>x;
    s3+=x;
    p3.push(x);
  }
  bool ok = false;
  while(!p1.empty()||!p2.empty()||!p3.empty()){
    int mx = max({s1,s2,s3});
    if(s1==s2 && s1==s3){ok=true;break;}
    if(s1==mx){
      int top =p1.front();
      p1.pop();
      s1-=top;
    }else if(s2==mx){
      int top =p2.front();
      p2.pop();
      s2-=top;
    }else if(s3==mx){
      int top = p3.front();
      p3.pop();
      s3-=top;
    }
  }
  cout<< (ok ? s1 : '0')<<'\n';  
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


