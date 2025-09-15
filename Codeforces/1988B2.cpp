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
  string s; cin>>s;
  int left = 0;
  int cnz = 0;
  int cno = 0;
  for(int i=0; i<n ; i++){
    if(s[i]=='1')cno++;
  }
  while(left<n){
    int right = left;
    while(right<n && s[right]==s[left]){
      right++;
    }
    if(s[left]=='0')cnz++;
    left = right;
  }
  cout<<(cno>cnz ? "YES" : "NO")<<'\n';
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

