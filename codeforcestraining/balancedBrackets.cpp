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
  int n = (int)s.size();
  stack<char> st;
  bool ok = true;
  for(int i=0;i<n;i++){
    if(s[i]=='('||s[i]=='{'||s[i]=='['){
      st.push(s[i]);
    }else{
      if(!st.empty() && (st.top()=='(' && s[i]==')'
          || st.top()=='{' && s[i]=='}'
          ||st.top()=='[' && s[i]==']')){
        st.pop();
      }else{
        cout<<"NO\n";
        return;
      }
    }
  }
  cout<<(st.empty()?"YES":"NO")<<'\n';
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

