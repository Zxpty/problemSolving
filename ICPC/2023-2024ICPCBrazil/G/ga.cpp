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
    map<int , pair<int ,int>> mp;
    pair<int, int> xmx, xmn, ymx, ymn;
    int pos1 , pos2 , pos3 , pos4 ; pos1 = pos2 = pos3 = pos4 = 0;
    xmx = xmn = ymx = ymn = {-1,-1};
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        int x_max = xmx.first;
        if (x_max > x) {
            xmx.first = x;
            xmx.second = y;               
            pos1 = i;
        }

        int x_min = xmn.first;
        if ( x_min < x) {
            xmn.first = x;
            xmn.second =y;   
            pos2 = i;
        }

        int y_max = ymx.second;
        if ( y_max > y) {
            ymx.first = x;
            ymx.second = y;
            pos3 = i;
            
        }

        int y_min = ymn.second;
        if ( y_min < y) {
            ymn.first = x;
            ymn.second = y;
            pos4 = i;

        }
    }
    
    
    cout << pos1 << ' '<< pos2<< ' ' << pos3 << ' '<< pos4;
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