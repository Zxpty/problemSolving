#include <bits/stdc++.h>
#include <cstdlib>
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
    int n;
    cin >> n;
    vector<ll> r(n+1);
    r[0] = 0;
    for(int i=1;i<n+1;i++){
      int num; cin>>num;
      r[i]=num;
    }

    set<int> p(r.begin(),r.end());
    if(p.size()!=r.size()){
      ll sum = 0;
      for(auto x : p){
        sum+=x;
      }
      cout<<sum;
    }else{

    ll mn_ans = r[1];
    for(int i=2;i<n+1;i++){
      mn_ans+=min(abs(r[i]-r[i-2]),abs(r[i]-r[i-2]));
    }
    dbg(mn_ans);
    cout<<mn_ans;
    }

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

