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
    map <char,pair<int, int>> m = {
        {'I', {0, 1}}, {'V', {1, 5}}, {'X', {2, 10}}, 
        {'L', {3, 50}}, {'C', {4, 100}}, {'D', {5, 500}}, {'M', {6, 1000}}};
    string s; cin>>s;
    int n = (int)s.size();
    reverse(s.begin(),s.end());
    ll sum = m[s[0]].second;
    int left = 0;
    while(left<n){
      int right = left+1;
      while(right<n && m[s[left]].first>m[s[right]].first){
        sum-=m[s[right]].second;
        right++;
      }
      sum+=m[s[right]].second;
      left = right;
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


