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
  int n; cin>>n;
  stack<int> st;
  auto check =[&](string s){
    if(s.size()>1)return false;
    return not isdigit(s[0]);
  };
  for(int i=0;i<n;i++){
    string s; cin>>s;
    if(check(s)){
      int a = st.top();st.pop();
      int b = st.top();st.pop();
      if(s[0]=='+')st.push(b+a);
      if(s[0]=='-')st.push(b-a);
      if(s[0]=='*')st.push(a*b);
      if(s[0]=='/')st.push(b/a);
    }else{
      st.push(atoi(s.c_str()));
    }
    dbg(st);
  }
  cout<<st.top()<<'\n';
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

