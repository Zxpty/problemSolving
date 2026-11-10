// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c, d; cin >> a >> b >> c >> d;
    long long l = 1, r = 1e18;
    while(l < r) {
        long long m = (l + r) / 2;
        bool ok = true;
        ok &= (m / 2 >= a);
        ok &= (m / 3 >= b);
        ok &= (m / 5 >= c);
        ok &= (m / 7 >= d);
        if(ok) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << ' ';
    long long ans = 0;
    long long div = l;
    while(div >= 2) {
        div /= 2;
		ans += div;
    }
    cout << ans;
}

