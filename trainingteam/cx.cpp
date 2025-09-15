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
  map < char, pair<int, int>> m = {
        {'I', {1, 1}}, {'V', {2, 5}}, {'X', {3, 10}}, {'L', {4, 50}}, {'C', {5, 100}}, {'D', {6, 500}}, {'M', {7, 1000}}};
  string s; cin>>s;
  reverse(s.begin(),s.end());
  int n = (int)s.size();
  ll sum = 0;
  sum+=1LL*m[s[0]].second;
  for(int i=1;i<n;i++){
    if(m[s[i]].first<m[s[i-1]].first){
      sum-=m[s[i]].second;
    }else sum+=m[s[i]].second;
  }
  cout<<sum<<'\n';
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

