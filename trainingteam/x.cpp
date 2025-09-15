#include <bits/stdc++.h>
#define cpu()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
void solve()
{
    string s; cin>>s;
    map < char, pair<int, int>> m = {
        {'I', {1, 1}}, {'V', {2, 5}}, {'X', {3, 10}, {'L', {4, 50}}, {'C', {5, 100}}, {'D', {6, 500}}, {'M', {7, 1000}}};
    };
    int n = (int)s.size();
    int sum_total = 0;
    for(int i=0;i<n;i++){
        sum_total+=m[s[i]];
    }
    int left = 0;
    while(left<n){
        int right = left;
        int k = 0;
        while(right+1<n && s[right]==s[left]){
            k++;
        }
        if(m[s[right+1]].first>m[s[left]].first){
            sum_total-=((k*m[left].first)*2);
        }
    }
    cout<<sum_total<<'\n';
    
}
int main()
{
    cpu();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
