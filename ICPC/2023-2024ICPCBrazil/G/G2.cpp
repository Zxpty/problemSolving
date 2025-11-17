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
    vector<array<int, 3>> r(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        r[i][0] = i + 1;
        r[i][1] = x;
        r[i][2] = y;
    }
    vector<array<int, 3>> q = r;
    sort(r.begin(), r.end(), [&](auto a, auto b){
        return a[1] < b[1]; 
    });

    sort(r.begin(), r.end(), [&](auto a, auto b){
        return a[2] < b[2]; 
    });

    vector<int> ans = {q[0][0], q[n-1][0], r[0][0], r[n-1][0]};
    sort(ans.begin(), ans.end());
    for (int x : ans) {
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