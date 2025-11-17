#include <bits/stdc++.h>
#define cpu() ios::sync_with_stdio(0);cin.tie(0);
using namespace std;

void solve(){
    int n; cin >> n;
    if (n <= 4) {
        for (int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        return;
    }
    //vector<pair<int, pair<int, int>> v(n);
    set<int> st;
    pair<int, pair<int, int>> xmx, xmn, ymx, ymn;
    xmx = ymx = {-1, {-1, -1}};
    ymn = xmn = {-1, {INT_MAX, INT_MAX}};
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        int x_max = xmx.second.first;
        if (!st.count(i) && x_max < x) {
            xmx.first = i;
            xmx.second = {x, y};
            st.insert(i);
        }

        int x_min = xmn.second.first;
        if (!st.count(i) && x_min > x) {
            xmn.first = i;
            xmn.second = {x, y};
            st.insert(i);
        }

        int y_max = ymx.second.second;
        if (!st.count(i) && y_max < y) {
            ymx.first = i;
            ymx.second = {x, y};
            st.insert(i);
        }

        int y_min = ymn.second.second;
        if (!st.count(i) && y_min > y) {
            ymn.first = i;
            ymn.second = {x, y};
            st.insert(i);
        }
    }
    vector<pair<int, pair<int, int>>> v;

    if (ymn.first != -1) v.push_back(ymn);
    if (ymx.first != -1) v.push_back(ymx);
    if (xmn.first != -1) v.push_back(xmn);
    if (xmx.first != -1) v.push_back(xmx);
    sort(v.begin(), v.end());
    for (auto [x, _] : v) {
        cout << x << ' ';
    }
}

int main() {
    cpu();
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}