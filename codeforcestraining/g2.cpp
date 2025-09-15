#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll MX = 1e6+1;
vector<pair<ll,ll>> pre(MX+1);
void init(){
    for(ll i=1;i<=MX;i++){
        pre[i]={((i*(i+1))/2),i};
    }
}
void solve()
{
  dbg(pre[MX-1]);
    ll d; cin>>d;
    ll target = d;
    ll left = 1;
    ll right = MX;
    vector<pair<ll,ll>> ans;
    while(left<right){
        if((pre[right].first-pre[left].first)==target){
            ans.push_back({pre[right].second,pre[left].second});
            right--;
            left++;
        }
        if((pre[right].first - pre[left].first)<target){
          left++;
        }else{
          right--;
        }
    }
    cout<<(int)ans.size()<<'\n';
    for(auto x : ans){
        cout<<x.second<<" "<<x.first<<'\n';
    }
}
int main()
{
    cpu();
    init();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
