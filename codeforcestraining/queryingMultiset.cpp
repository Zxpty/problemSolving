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
  int n = (int)s.size();
  int left = 0;
  int mx = -1;
  while(left<n){
    int right = left;
    int cn = 0;
    while(right<n && s[left]==s[right]){
      cn++;
      right++;
    }
    mx = max(mx,cn);
    left = right;
  }
  cout<<mx<<'\n';
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

