#include <bits/stdc++.h>
#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif
#define cpu()                    \
ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
void solve()
{
    ll d;
    cin >> d;
    vector<pair<ll, ll>> p;
    p.push_back({d, d - 1});
    ll r = (d / 2) + 1;

    vector<ll>difff;
    for (ll i = 2; i < r; i++)
    {
        difff.push_back(i);
    }
    
    for (ll i = 0; i < difff.size(); i++)
    {
        
    }
    

    cout << (int)p.size() << '\n';
    for (auto x : p)
    {
        cout << x.second << ' ' << x.first << '\n';
    }
    dbg(p);
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
