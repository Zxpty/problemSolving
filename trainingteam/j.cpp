#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> sumas;
    for (int i = 0; i < n; i++)
    {
        sumas.push_back(v[i]);
        for (int j = i + 1; j < n; j++)
        {
            sumas.push_back(v[i] + v[j]);
        }
    }
    sort(sumas.begin(), sumas.end());
    for(auto a : sumas) {
        cout << a << " ";
    }
    cout << "\n";
    ll ans = 0;
    for (int i = 0; i < sumas.size(); i++)
    {
        ll elemnt = 0;
        for (int j = 0; j < sumas.size(); j++)
        {
            if(sumas[j] <= sumas[i]) {
                elemnt++;
            }
        }
        if(elemnt >= n) {
            ans = sumas[i];
        }
    }
    cout << ans << "\n";
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
