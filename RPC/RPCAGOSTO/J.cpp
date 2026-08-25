#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin>>n;

    map <long long , vector<long long>> mp;

    long long ans = 0;

    for(int i = 0; i < 2 * n; i++) {
        long long d,a,c; cin>>d>>a>>c;

        ans += a;
        mp[c].push_back(d - a);
    }

    vector<long long> gain;

    for (auto &x : mp) {
        sort(x.second.rbegin(), x.second.rend());

        int m = x.second.size();

        for (int i = 0; i < m; i++) {
            long long cur = x.second[i];

            if (i < m/2) cur += x.first;
            else if (m%2 == 1 && i == m/2);
            else cur -= x.first;

            gain.push_back(cur);
        }
    }

    sort(gain.rbegin(), gain.rend());

    for(int i = 0; i < n; i++) {
        ans += gain[i];
    }

    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}

