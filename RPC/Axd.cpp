#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(false);cin.tie(nullptr);
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
void solve()
{
    int n, l; cin >> n >> l;
    vector<string> v(n);
    vector<string> ans(n);
    for(auto &x : v) cin >> x;
    int rows = 0;
    for(int i = 0; i < n; i++) {
        int subL = v[i].length(); // 4
        int left = (l - subL) / 2; // (7 - 4) / 2 = 1
        int right = (l - subL) - left; // 7 - 4 - 1 = 2
        if(left != right) {
            if(rows % 2 != 0) {
                left = max(left, right); // (1, 2); left -> 2
            } else {
                left = min(left, right);
            }
            rows++;
        }
        right = l - subL - left; // 7 - 4 -  2
        string s1 = "", s2 = "";
        while (left--)
        {
            s1 += ".";
        }
        while (right--)
        {
            s2 += ".";
        }
        ans[i] = s1 + v[i] + s2;
    }
    for(auto x : ans) {
        cout << x << '\n';
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
