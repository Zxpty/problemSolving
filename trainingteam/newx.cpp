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
    ll sum_total = 0;
    for(int i=0;i<n;i++){
        sum_total+=1LL*m[s[i]].second;
    }
    dbg(s);
    int left = 0;
    while(left<n){
        int right = left;
        int k = 0;
        while(right<n && s[right]==s[left]){
            right++;
            k++;
        }
        dbg(k);
        dbg("indice left: ",left);
        dbg("indice right: ",right);
        dbg(m[s[right]].first);
        dbg(m[s[left]].first);

        if(m[s[right]].first>m[s[left]].first){
          dbg(k);
          dbg(m[s[left]].second);
          sum_total= (1LL)*(sum_total-(k*m[s[left]].second*2));
          dbg(sum_total);
          dbg(k*m[left].second*2);
          dbg(sum_total);
        }
        left = right;
    }
    cout<<sum_total<<'\n';

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

